#include <wchar.h>
#include <stdio.h>
#include "struct.h"

int main() {
  // init matrices
  Matrix2D *matrix1 = matrix2d_construct_default();
  Matrix2D *matrix2 = matrix2d_construct_default();
  Matrix2D *matrix = matrix1; // current matrix
  
  int choice = 0;
  int sub_choice = 0;
  int matrix_choice = 1;

  fputws(L"This is an app for testing work with matrices.\n\n", stdout);
  do {
    fputws(L"Choose what to do:\n", stdout);
    fputws(L"(1)  Compare two matrices\n", stdout);
    fputws(L"(2)  Input matrix\n", stdout);
    fputws(L"(3)  Print matrix\n", stdout);
    fputws(L"(4)  Change matrix values\n", stdout);
    fputws(L"(5)  Fill matrix with random values\n", stdout);
    fputws(L"(6)  Get matrix row\n", stdout);
    fputws(L"(7)  Get matrix col\n", stdout);
    fputws(L"(8)  Transpose matrix\n", stdout);
    fputws(L"(9)  Find the determinant of matrix\n", stdout);
    fputws(L"(10) Find the inverse matrix\n", stdout);
    fputws(L"(11) Change active matrix\n", stdout);
    /*
    fputws(L"Matrices to choose:\n", stdout);
    fputws(L"matrix1", stdout);
    if (matrix_choice == 1) fputws(L" (active)", stdout);
    putwchar(L'\n');
    fputws(L"matrix2", stdout);
    if (matrix_choice == 2) fputws(L" (active)", stdout);
    putwchar(L'\n');
    */
  } while (choice>0 && choice<11);

  return 0;
}
