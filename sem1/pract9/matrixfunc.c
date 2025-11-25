#include <stdio.h>
#include "matrixfunc.h"

// left-to-right row-based input from file <
void stdin_matrix(int matrix[COL][ROW]) {
  int cols=0, ch=0;
  int *ptr = &matrix[cols][0];
  do {
    scanf("%d", ptr++);
    if (ch=='\n') ptr=&matrix[++cols][0];
  } while ((ch=getchar())!=EOF);
}
// prints matrix of values with specified indeces
void stdout_matrix(int matrix[COL][ROW]) {
  for (int i=0; i<3; i++) putchar(' ');
  for (int i=0; i<ROW; i++) printf("  %d   ", i);
  int *ptr = &matrix[0][0];
  putchar('\n');
  for (int i=0; i<COL; i++) {
    printf("%2d ", i);
    for (int j=0; j<ROW; j++) printf("[%3d] ", *(ptr+i*COL+j));
    putchar('\n');
  }
}
// prints indices elements whose values are greater than the given k from m column to l
void find_grtrk_m_l(int matrix[COL][ROW], int k, int m, int l) {
  printf("matrix[i][j] > %d; (i, j) indeces:  ", k);
  int *ptr = &matrix[0][0];
  for (int i=m; i<=l; i++) {
    for (int j=0; j<ROW; j++) if (*(ptr+i*COL+j) > k) printf("(%d, %d) ", i, j);
    putchar('\n');
  }
}
// the sum of all elements that are multiple of k
int sum_mltk(int matrix[COL][ROW], int k) {
  int sum=0;
  int *ptr = &matrix[0][0];
  for (int i=0; i<COL; i++) {
    for (int j=0; j<ROW; j++) 
      sum += (*(ptr+i*COL+j)%k) ? (0) : *(ptr+i*COL+j);
  }
  return sum;
}
