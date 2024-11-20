#include <stdio.h>
#include <stdlib.h>

void mayWeather(int matrix[][6], int newMat[][6]);
void printMatrix(int matrix[][6]);

int main(){
    int matrix[6][6] = {{0, 69000, 69000, 690000, 6, 3}, {4, 0, 3, 69000, 6, 10}, {4, 69000, 0, 6, 69000, 69000}, {8, 6, 69000, 0, 3, 69000}, {69000, 69000, 6, 69000, 0, 6}, {69000, 3, 69000, 3, 69000, 0}};
    int newMat[6][6];
    
    mayWeather(matrix, newMat);
    printMatrix(newMat);
    return 0; 
}

void mayWeather(int matrix[][6], int newMat[][6]){
    int i, j, k;
    
    for(i = 0; i < 6; ++i){
        for(j = 0; j < 6; ++j){
            newMat[i][j] = matrix[i][j]; 
        }
    }
    
    for(i = 0; i < 6; ++i){
        newMat[i][i] = 0; 
    }
    
    for(i = 0; i < 6; ++i){
        for(j = 0; j < 6; ++j){
            for(k = 0; k < 6; ++k){
                if(newMat[j][i] + newMat[i][k] < newMat[j][k]){
                    newMat[j][k] = newMat[j][i] + newMat[i][k];
                }
            }
        }
    }
}

void printMatrix(int matrix[][6]){
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
