#include <stdio.h>
#include <stdlib.h>

int** my2DAlloc(int rows, int cols){
  if (rows <= 0 || cols <= 0) {
    return NULL;
  }
  int i;
  int header = rows * sizeof(int*);
  int data = rows * cols * sizeof(int);
  int** rowptr = (int**)malloc(header + data);
  if (rowptr == NULL) {
    return NULL;
  }
  int* buf = (int*)(rowptr + rows);
  for (i = 0; i < rows; ++i) {
    rowptr[i] = buf + cols * i;
  }
  return rowptr;
}


void my2DFree(int** matrix){
  free(matrix);
}

int main(int argc, char** argv){
  int** matrix = my2DAlloc(10, 5);
  if (matrix != NULL) {
    matrix[1][1] = 5;
    my2DFree(matrix);
  }
  return 0;
}
