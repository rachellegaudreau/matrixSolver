#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void printMatrix(int** matrix, int row, int col){
    for(int j = 0; j < row; j++){
        for(int i = 0; i < col; i++){
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

int** getMatrix(int row, int col){
    int **result = (int**)malloc(sizeof(int*)*row);
    for(int i = 0; i < row; i++){
        result[i] = (int*)malloc(sizeof(int)*col);
    }
    return result;
}

int** addMatrix(int ** num1, int ** num2, int row, int col){
    int** result = getMatrix(row, col);
    for(int j=0; j<row;j++){
        for(int i=0; i<col;i++){
            result[j][i]=num1[j][i]+num2[j][i];
        }
    }
    return result;
}

int** subtractMatrix(int** num1, int** num2, int row, int col){
    int** result = getMatrix(row, col);
    for(int j=0; j<row;j++){
        for(int i=0; i<col;i++){
            result[j][i]=num1[j][i]-num2[j][i];
        }
    }
    return result;
}

int** multMatrix(int** num1, int** num2, int row, int col){
    if(row != col){
        printf("Columns and Rows do not match!!\n");
        return 0;
    }
    int** result = getMatrix(row, col);
    for(int j=0; j<row;j++){
        for(int i=0; i<col;i++){
            result[j][i]= result[j][i] + (num1[j][i] * num2[j][i]);
        }
    }
    return result;
}

// determinant
// (-1)^(row+col)row1entry1(recursive)+(-1)^(row+col)row1entry2(recursive)...
// lets use col1 and go through rows
// det of matrix without first col or i row

int detMatrix(int** matrix, int row, int col){
    int result = 0;
    if(row!=col){
        printf("Cannot compute determinant for non-square matrix!");
        return 0;
    }
    if(row==2 && col==2){
        int detSmall = (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
        return detSmall;
    }
    for(int i = 0; i<row; i++){
        int** newMatrix = getMatrix(row-1,col-1);
        // segmentation fault from the jump i think
        int jump = 0;
        for(int r=0; r<row-1; r++){
            for(int c=1; c<col; c++){
                if(r==i){
		  jump++;
                    newMatrix[r][c-1]= matrix[r+jump][c];
                    continue;
                }
                newMatrix[r][c-1]= matrix[r+jump][c];
            }
        }
	//got rid of the pow() function, doesnt work
        result = result + matrix[0][i]*detMatrix(newMatrix,row-1,col-1);
    }
    return result;
}

int main(int argc, char **argv){
    if(argc<3){
        printf("How to use: <rows> <columns> <matrix_entries> \n");
        return 1;
    }

    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    int totEntries = argc-3; 
    int numPerMatrix = row*col;

    if(totEntries < numPerMatrix * 2){
        printf("Not enough entries for two matrices; filled in with zeros...\n");
    }

    // allocating space for 2d matrix
    int **matrixOne = (int**)malloc(sizeof(int*)*row);
    int **matrixTwo = (int**)malloc(sizeof(int*)*row);
    
    for(int i = 0; i < row; i++){
        matrixOne[i]=(int*)malloc(sizeof(int)*col);
        matrixTwo[i]=(int*)malloc(sizeof(int)*col);
    }

    printf("Rows: %d \n", row);
    printf("Columns: %d \n", col);
    int index = 3; // since 1 and 2 are rows and cols

    // fill in Matrix 1
    for(int j = 0; j < row; j++){
        for(int i = 0; i < col; i++){
            if(argv[index] != NULL){
                matrixOne[j][i]= atoi(argv[index]);
                index++;
            } else {
                matrixOne[j][i]=0;
            }
        }
    }

    // fill in Matrix 2
    for(int j = 0; j < row; j++){
        for(int i = 0; i < col; i++){
            if(argv[index] != NULL){
                matrixTwo[j][i]=atoi(argv[index]);
                index++;
            } else {
                matrixTwo[j][i]=0;
            }
        }
    }

    // print matrix 1
    printf("Matrix 1: \n");
    printMatrix(matrixOne, row, col);

    // print matrix 2
    printf("Matrix 2: \n");
    printMatrix(matrixTwo, row, col);  
    
    printf("Matrix Sum: \n");
    printMatrix(addMatrix(matrixOne,matrixTwo,row,col), row, col);
    printf("Matrix Difference: \n");
    printMatrix(subtractMatrix(matrixOne,matrixTwo,row,col),row,col);
    printf("Matrix Product: \n");
    printMatrix(multMatrix(matrixOne,matrixTwo,row,col), row, col); 
    printf("Matrix One Determinant: \n");
    printf(" %d \n", detMatrix(matrixOne, row, col));
    
    for(int i = 0; i < row; i++){
        free(matrixOne[i]);
        free(matrixTwo[i]);
    }
    free(matrixOne);
    free(matrixTwo);

    return 0;
}
