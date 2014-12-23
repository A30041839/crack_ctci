#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int m, int n){
  int i, j;
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      printf("%d,", matrix[i][j]);
    }
    printf("\n");
  }
}

int** my2DAlloc(int m, int n){
  if (m <=0 || n <=0) return NULL;
  int** matrix = (int**)malloc(m * sizeof(int*));//malloc(size_in_byte)
  if (matrix == NULL) exit(1);
  int i;
  matrix[0] = (int*)malloc(m * n * sizeof(int));
  if (matrix[0] == NULL){
    free(matrix);
    return NULL;
  }
  for (i = 1; i < m; ++i){
    matrix[i] = matrix[0] + i * n;
  }
  return matrix;
}


void my2DFree(int** matrix, int m, int n){
  if (matrix != NULL){
    free(matrix[0]);
    free(matrix);
  }
}

int main(int argc, char** argv){
  int** matrix = my2DAlloc(10, 5);
  matrix[1][1] = 5;
  printMatrix(matrix, 10, 5);
  my2DFree(matrix, 10, 5);
  return 0;
}
