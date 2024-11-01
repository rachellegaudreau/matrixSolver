#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc<3){
        printf("How to use: <rows> <columns> <matrix_entries> \n");
        return 1;
    }

    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    int totEntries = argc-3;
    int numPerMatrix = row*col;

    /*
    if(totEntries < numPerMatrix*2){
        printf("Make sure to include your matrix numbers...\n");
        printf("Not enough entries for two matrices.\n");
        return 1;
    }
    */

    int **matrixOne = (int**)malloc(sizeof(int*)*row);
    int **matrixTwo = (int**)malloc(sizeof(int*)*row);
    
    for(int i=0; i<row; i++){
        matrixOne[i]=(int*)malloc(sizeof(int)*col);
        matrixTwo[i]=(int*)malloc(sizeof(int)*col);
    }

    printf("Rows: %d \n", row);
    printf("Columns: %d \n", col);
    int index = 3;


    for(int j = 0; j< row; j++){
        for(int i = 0; i< col; i++){
            if(argv[index]!= NULL){
                matrixOne[j][i]= atoi(argv[index]);
                index++;
            } else {
                matrixOne[j][i]=0;
            }
        }
    }
    //index++;

    // take in entries
    for(int j = 0; j< row; j++){
        for(int i = 0; i< col; i++){
            if(argv[index]!= NULL){
                matrixTwo[j][i]=atoi(argv[index]);
                index++;
            } else {
                matrixTwo[j][i]=0;
            }
        }
    }

    // print matrix 1
    printf("Matrix 1: \n");
    for(int j=0; j< row; j++){
        for(int i=0; i< col; i++){
            printf("%d ", matrixOne[j][i]);
        }
        printf("\n");
    }

    // print matrix 2
    printf("Matrix 2: \n");
    for(int j=0; j< row; j++){
        for(int i=0; i< col; i++){
            printf("%d ", matrixTwo[j][i]);
        }
        printf("\n");
    }    

    //add 
    
    //subtract 

    //multiply

    for(int i=0; i<row; i++){
        free(matrixOne[i]);
        free(matrixTwo[i]);
    }
    free(matrixOne);
    free(matrixTwo);

    return 0;
}
