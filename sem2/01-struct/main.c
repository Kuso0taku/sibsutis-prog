#include <wchar.h>
#include <stdio.h>
#include "struct.h"

int main() {
  // init matrices
  Matrix2D *matrix1 = matrix2d_construct_default();
  Matrix2D *matrix2 = matrix2d_construct_default();
  Matrix2D *active_matrix = matrix1; // current matrix
  Matrix2D *other_matrix = matrix2; // second matrix
  Matrix2D *result_matrix = NULL; // matrix for results (get row/col or inverse)
  
  int choice = 0;
  int sub_choice = 0;
  int matrix_choice = 1;
  
  int code = 0;
  fputws(L"This is an app for testing work with (float) matrices.\n\n", stdout);
  do {
    fputws(L"Choose what to do:\n", stdout);
    fputws(L"(1)  Compare two matrices\n", stdout);
    fputws(L"(2)  Input the matrix\n", stdout);
    fputws(L"(3)  Print the matrix\n", stdout);
    fputws(L"(4)  Change the matrix values\n", stdout);
    fputws(L"(5)  Fill the matrix with random values\n", stdout);
    fputws(L"(6)  Get the matrix row\n", stdout);
    fputws(L"(7)  Get the matrix col\n", stdout);
    fputws(L"(8)  Transpose the matrix\n", stdout);
    fputws(L"(9)  Find the determinant of the matrix\n", stdout);
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
      // Exit
      case 0: 
        fputws(L"Thanks for using me!\n", stdout);
        return 0;

      // Compare
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
        
        _Bool cmp = 0;

        // type of comparing
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

      // input
      case 2:
        code = matrix2d_wscanf(active_matrix);
        if (code == WEOF) return -1;
        break;

      // output
      case 3:
        matrix2d_wprintf(active_matrix);
        break;

      // change values 
      case 4:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        fputws(L"What do you want to do?\n", stdout);
        fputws(L"(1) Increment every element in the matrix\n", stdout);
        fputws(L"(2) Decrement every element in the matrix\n", stdout);
        fputws(L"(3) Change a specific element in the matrix\n", stdout);
        putwchar(L'\n');

        wprintf(L"Enter your choice: ");
        while ((code = wscanf(L"%d", &sub_choice))!=1 || 
          sub_choice<1 || sub_choice>3) {
          if (code == WEOF) {
            wprintf(L"WEOF ERROR! ABORTING.\n");
            return -1;
          }
          while (getwchar() != L'\n');
          wprintf(L"Invalid input! Try again: ");
        }
        
        // type of change
        switch (sub_choice) {
          case 1: matrix2d_increment(active_matrix); break;
          case 2: matrix2d_decrement(active_matrix); break;
          case 3:
            int row=0, col=0;
            float value=0;

            wprintf(L"Enter the row INDEX of the element to change: ");
            while ((code = wscanf(L"%d", &row))!=1 || 
            row<0 || row>active_matrix->rows) {
              if (code == WEOF) {
                wprintf(L"WEOF ERROR! ABORTING.\n");
                return -1;
              }
              while (getwchar() != L'\n');
              wprintf(L"Invalid input! Try again: ");
            }

            wprintf(L"Enter the column INDEX of the element to change: ");
            while ((code = wscanf(L"%d", &col))!=1 || 
              col<0 || col>active_matrix->cols) {
              if (code == WEOF) {
                wprintf(L"WEOF ERROR! ABORTING.\n");
                return -1;
              }
              while (getwchar() != L'\n');
              wprintf(L"Invalid input! Try again: ");
            }

            wprintf(L"Enter the value of the element to change: ");
            while ((code = wscanf(L"%f", &value))!=1) {
              if (code == WEOF) {
                wprintf(L"WEOF ERROR! ABORTING.\n");
                return -1;
              }
              while (getwchar() != L'\n');
              wprintf(L"Invalid input! Try again: ");
            }
            
            matrix2d_setter(active_matrix, row, col, value);
            break;
        }

        break;
      
      // fill with random values
      case 5:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        float min=0, max=0;

        wprintf(L"Enter the minimal value of random number: ");
        while ((code = wscanf(L"%f", &min))!=1) {
          if (code == WEOF) {
            wprintf(L"WEOF ERROR! ABORTING.\n");
            return -1;
          }
          while (getwchar() != L'\n');
          wprintf(L"Invalid input! Try again: ");
        }
        
        wprintf(L"Enter the maximum value of random number: ");
        while ((code = wscanf(L"%f", &max))!=1 || max<min) {
          if (code == WEOF) {
            wprintf(L"WEOF ERROR! ABORTING.\n");
            return -1;
          }
          while (getwchar() != L'\n');
          if (max<min) wprintf(L"Max value must be greater than or equal to min! ");
          else wprintf(L"Invalid input! ");
          wprintf(L"Try again: ");
        }
        
        matrix2d_random(active_matrix, min, max);
        break;

      // get row 
      case 6:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        wprintf(L"Enter the row INDEX of the matrix: ");
        while ((code = wscanf(L"%d", &sub_choice))!=1 || 
          sub_choice<0 || sub_choice>active_matrix->rows) {
          if (code == WEOF) {
            wprintf(L"WEOF ERROR! ABORTING.\n");
            return -1;
          }
          while (getwchar() != L'\n');
          wprintf(L"Invalid input! Try again: ");
        }

        matrix2d_wprintf(matrix2d_get_row(active_matrix, sub_choice));
        break;

      // get col
      case 7:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        wprintf(L"Enter the column INDEX of the matrix: ");
        while ((code = wscanf(L"%d", &sub_choice))!=1 || 
          sub_choice<0 || sub_choice>active_matrix->rows) {
          if (code == WEOF) {
            wprintf(L"WEOF ERROR! ABORTING.\n");
            return -1;
          }
          while (getwchar() != L'\n');
          wprintf(L"Invalid input! Try again: ");
        }

        matrix2d_wprintf(matrix2d_get_col(active_matrix, sub_choice));
        break;
      
      // transpose
      case 8:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        active_matrix = matrix2d_transpose(active_matrix);
        break;

      // determinant 
      case 9:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        if (active_matrix->rows != active_matrix->cols) {
          fputws(L"Oops! The matrix must be square!\n", stdout);
          break;
        }
        
        wprintf(L"The determinant of the matrix is %.2f\n", 
                matrix2d_determinant(active_matrix));
        break;

      // find the inverse matrix 
      case 10:
        if (!active_matrix->data) {
          fputws(L"Oops! The matrix is empty! First, input one\n", stdout);
          break;
        }

        if (active_matrix->rows != active_matrix->cols) {
          fputws(L"Oops! The matrix must be square!\n", stdout);
          break;
        }

        if (!matrix2d_determinant(active_matrix)) {
          fputws(L"Oops! The determinant must not be 0!\n", stdout);
          break;
        }

        matrix2d_wprintf(matrix2d_inverse(active_matrix));
        break;
    }

    putwchar(L'\n');
  } while (choice>0 && choice<11);

  return 0;
}
