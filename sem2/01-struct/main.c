#include <wchar.h>
#include <stdio.h>
#include "struct.h"

int main() {
  // init matrices
  Matrix2D *matrix1 = matrix2d_construct_default();
  Matrix2D *matrix2 = matrix2d_construct_default();
  Matrix2D *result_matrix = NULL;
  Matrix2D *active_matrix = matrix1; // current matrix
  Matrix2D *other_matrix = matrix2; // second matrix
  
  int choice = 0;
  int sub_choice = 0;
  int matrix_choice = 1;
  float det = 0;
  _Bool cmp = 0;
  
  int code = 0;
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
    fputws(L"\n(0)  Exit\n", stdout);
    putwchar('\n');
    /*
    fputws(L"Matrices to choose:\n", stdout);
    fputws(L"matrix1", stdout);
    if (matrix_choice == 1) fputws(L" (active)", stdout);
    putwchar(L'\n');
    fputws(L"matrix2", stdout);
    if (matrix_choice == 2) fputws(L" (active)", stdout);
    putwchar(L'\n');
    */

    wprintf(L"Enter your choice: ");
    while ((code = wscanf(L"%d", &choice))!=1 || choice<0 || choice>11) {
      if (code == WEOF) {
        wprintf(L"WEOF ERROR! ABORTING.\n");
        return -1;
      }
      while (getwchar() != L'\n');
      wprintf(L"Invalid input! Try again: ");
    }
    
    putwchar(L'\n');
    
    switch (choice) {
      case 0: 
        fputws(L"Thanks for using me!\n", stdout);
        return 0;
      case 1: 
        fputws(L"Avaliable compares are:\n", stdout);
        fputws(L"(1) Greater than\n", stdout);
        fputws(L"(2) Less than\n", stdout);
        fputws(L"(3) Equal to\n", stdout);
        fputws(L"(4) Not equal to\n", stdout);
        fputws(L"(5) Greater than or equal to\n", stdout);
        fputws(L"(6) Less than or equal to\n", stdout);
        putwchar(L'\n');

        wprintf(L"Enter your choice: ");
        while ((code = wscanf(L"%d", &sub_choice))!=1 || 
          sub_choice<1 || sub_choice>6) {
          if (code == WEOF) {
            wprintf(L"WEOF ERROR! ABORTING.\n");
            return -1;
          }
          while (getwchar() != L'\n');
          wprintf(L"Invalid input! Try again: ");
        }
        
        cmp = 0;
        switch (sub_choice) {
          case 1: cmp = matrix2d_grtr(active_matrix, other_matrix); break;
          case 2: cmp = matrix2d_less(active_matrix, other_matrix); break;
          case 3: cmp = matrix2d_eql(active_matrix, other_matrix); break;
          case 4: cmp = matrix2d_not_eql(active_matrix, other_matrix); break;
          case 5: cmp = matrix2d_grtr_or_eql(active_matrix, other_matrix); break;
          case 6: cmp = matrix2d_less_or_eql(active_matrix, other_matrix); break;
        }
        
        if (cmp) fputws(L"True!\n", stdout);
        else fputws(L"False!\n", stdout);

        break;
    }

    putwchar(L'\n');
  } while (choice>0 && choice<11);

  return 0;
}
