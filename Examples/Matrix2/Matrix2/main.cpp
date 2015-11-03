#include <stdio.h>
#include <math.h>
#include "vectorMatrix.h"




int main(int argc, char **argv) {
    mat33 myMat1, myMat2;
    setMatrix(myMat1, 1, 2, 3, 1, 3, 4, 1, 4, 5);
    setMatrix(myMat2, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    printMatrix(myMat1);
    printMatrix(myMat2);
    
    
    mat33 mat = matrixMult(myMat1, myMat2);
    mat33 matT = matrixTranspose(mat);
    
    printMatrix(mat);
    printMatrix(matT);
    
}





