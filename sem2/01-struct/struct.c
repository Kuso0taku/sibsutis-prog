#include <wchar.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy
#include <math.h> // for fabs
#include "struct.h"


// memory methods
Matrix2D *matrix2d_construct_default() {
  Matrix2D* matrix = (Matrix2D*)malloc(sizeof(Matrix2D));
  matrix->rows = 0; matrix->cols = 0; matrix->data = NULL;
  return matrix;
}

Matrix2D *matrix2d_construct(Matrix2D* matrix, const size_t n, const size_t m, 
                             const float* arr) {
  if (matrix->rows * matrix->cols != n*m) {
    free(matrix->data);
    matrix->data = (float*)malloc(n*m * sizeof(float));
  }
  memcpy(matrix->data, arr, sizeof(float)*n*m);
  matrix->rows = n;
  matrix->cols = m;
  return matrix;
}

Matrix2D *matrix2d_construct_copy(Matrix2D* dst, Matrix2D* src) {
  if (src->data == NULL) dst->data = NULL;
  if (dst->rows * dst->cols != src->rows * src->cols) {
    free(dst->data);
    dst->data = (float*)malloc(src->rows * src->cols * sizeof(float));
  }
  memcpy(dst->data, src->data, sizeof(float) * src->rows * src->cols);
  dst->rows = src->rows;
  dst->cols = src->cols;
  return dst;
}

void matrix2d_destruct(Matrix2D* matrix) {
  matrix->rows = 0;
  matrix->cols = 0;
  free(matrix->data);
  matrix->data=NULL;
  free(matrix);
  matrix = NULL;
}

// matrix2d methods
// grade "Satisfactory"
int matrix2d_cmp(Matrix2D* m1, Matrix2D* m2) {
  if (m1->rows * m1->cols != m2->rows * m2->cols)
    return (m1->rows * m1->cols > m2->rows * m2->cols) ? 1 : -1;

  for (size_t i=0; i < m1->rows * m1->cols; i++) {
    if (fabs(*(m1->data+i) - *(m2->data+i)) > EPS) {
      if (*(m1->data+i) > *(m2->data+i)) return 1;
      else return -1;
    }
  }

  return 0;
}

int matrix2d_wscanf(Matrix2D* matrix) {
  size_t n=0, m=0;
  int code=0;
  
  wprintf(L"Enter the number of rows: ");
  while ((code = wscanf(L"%zu", &n))!=1) {
    if (code == WEOF) {
      wprintf(L"WEOF ERROR! ABORTING.\n");
      return -1;
    }
    while (getwchar() != L'\n');
    wprintf(L"Invalid input! Try again: ");
  }

  wprintf(L"Enter the number of cols: ");
  while ((code = wscanf(L"%zu", &m))!=1) {
    if (code == WEOF) {
      wprintf(L"WEOF ERROR! ABORTING.\n");
      return -1;
    }
    while (getwchar() != L'\n');
    wprintf(L"Invalid input! Try again: ");
  }

  float* arr = (float*)malloc(n*m * sizeof(float));
  wprintf(L"Enter %zu elements of matrix here:\n", n*m);
  for (size_t i=0; i<n*m; i++) {
    wprintf(L"Element [%zu][%zu]: ", i/m, i%m);
    while ((code = wscanf(L"%f", arr+i))!=1) {
      if (code == WEOF) {
        wprintf(L"WEOF ERROR! ABORTING.\n");
        return -1;
      }
      while (getwchar() != L'\n');
      wprintf(L"Invalid input! Try again: ");
    }
  }
  
  matrix2d_construct(matrix, n, m, arr);
  free(arr);
  matrix->rows = n;
  matrix->cols = m;

  return 0;
}

void matrix2d_wprintf(Matrix2D* matrix) {
  wprintf(L"rows: %zu\ncols: %zu\n", matrix->rows, matrix->cols);
  wprintf(L"{\n  ");
  for (size_t i=0; i<matrix->rows; i++) {
    putwchar(L'{');
    for (size_t j=0; j<matrix->cols-1; j++) {
      wprintf(L"%.2f, ", *(matrix->data+(i*matrix->cols)+j));
    }
    wprintf(L"%.2f}", *(matrix->data+(i*matrix->cols)+(matrix->cols-1)));
    if (i < matrix->rows - 1) wprintf(L",\n  ");
  }
  wprintf(L"\n}\n");
}

/*
void matrix2d_increment(Matrix2D*) {

}

void matrix2d_decrement(Matrix2D*) {

}

void matrix2d_setter(Matrix2D*) {

}

void matrix2d_random(Matrix2D*) {

}

// grade "Good"
float* matrix2d_get_row(Matrix2D*) {

}

float* matrix2d_get_col(Matrix2D*) {

}

float matrix2d_determinant(Matrix2D*) {

}

// grade "Excellent"
Matrix2D* matrix2d_inverse(Matrix2D*) {

}

*/
// some cmp funcs
_Bool matrix2d_eql(Matrix2D* m1, Matrix2D* m2) {
  return matrix2d_cmp(m1, m2) == 0;
}

_Bool matrix2d_not_eql(Matrix2D* m1, Matrix2D* m2) {
  return matrix2d_cmp(m1, m2) != 0;
}

_Bool matrix2d_grtr(Matrix2D* m1, Matrix2D* m2) {
  return matrix2d_cmp(m1, m2) > 0;
}

_Bool matrix2d_grtr_or_eql(Matrix2D* m1, Matrix2D* m2) {
  return matrix2d_cmp(m1, m2) >= 0;
}

_Bool matrix2d_less(Matrix2D* m1, Matrix2D* m2) {
  return matrix2d_cmp(m1, m2) < 0;
}

_Bool matrix2d_less_or_eql(Matrix2D* m1, Matrix2D* m2) {
  return matrix2d_cmp(m1, m2) <= 0;
}

/*
// other
void menu() {

}
*/
