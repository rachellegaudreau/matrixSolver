#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    int totEntries = argc-2;
    int numPerMatrix = row*col/2;

    if(totEntries <=0){
        printf("Make sure to include your matrix numbers...\n");
    }

    int **matrixOne = (int**)malloc(sizeof(int)*row);
    int **matrixTwo = (int**)malloc(sizeof(int)*numPerMatrix);
    int in = 0;

    for(int j = 0; j<=numPerMatrix; j++){
        for(int i = 0; i<=numPerMatrix; i++){
            in = scanf(" %d", &in);
            matrixOne[j][i]= in;
            
            //    char buf[100];
            //    scanf(" %s", buf);
            //    printf("Input %s not recognised... Quitting\n", buf);
            //    break;
        }
    }

    in=0;
    for(int j = numPerMatrix; j<=totEntries; j++){
        for(int i = numPerMatrix; i<=totEntries; i++){
            in = scanf(" %d", &in);
            matrixTwo[j-numPerMatrix][i-numPerMatrix]=in;

            //    char buf[100];
            //    scanf(" %s", buf);
            //    printf("Input %s not recognised... Quitting\n", buf);
            //    break;
        }
    }

    //repeat matrix1 in nice set up
    printf("Matrix 1: \n");
    for(int j=0; j<=numPerMatrix; j++){
        for(int i=0; i<=numPerMatrix; i++){
            printf("%d ", matrixOne[j][i]);
        }
        printf("\n");
    }

    //add 
    
    //subtract 

    //multiply

    return 0;
}
