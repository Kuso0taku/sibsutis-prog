#include <stdio.h>
#include <ctype.h> // tolower()
#include "myarrfunc.h"

int main() {
  int choice=0, k=0, ch=0;
  int m=0;
  do {
    // init size of array
    int n=0;
    printf("Enter array length: ");
    while(scanf("%d", &n) != 1 || n<=0) {
      printf("Wrong input! The num must be >= 0! Enter correct value here: ");
      while (getchar()!='\n');
    }
  
    // init array
    int arr[n];
    for (int i=0; i<n; i++) {
      printf("Enter the %d element: ", i+1);
      while(scanf("%d", arr+i) != 1) {
        printf("Wrong input! Enter correct value here: ");
        while (getchar()!='\n');
      }
    }
  
    putchar('\n');
    m=fnd_max(arr, n);
    // prints menu
    for (int i=0; i<35; i++) putchar('*');
    putchar('\n');
    puts("(1) Print values of array elements");
    puts("(2) Print addresses of array elements");
    puts("(3) Find last positive element");
    puts("(4) Count elements multiple of k");
    puts("(5) Count elements greater than average value of the array");
    puts("(6) Exit");
    for (int i=0; i<35; i++) putchar('*');
    putchar('\n');

    // reads choice
    printf("Enter your choice: ");
    while(scanf("%d", &choice) != 1 || choice<1 || choice>6) {
      printf("Wrong input! The input must be a number from 1 to 4!\n"
             "Enter correct value here: ");
      while (getchar()!='\n');
    }
    
    // choice processing
    if (choice==6) break;
    switch (choice) {
      case 1: {
        print_arr_val(arr, n);
        break;
      }
      case 2: {
        print_arr_ptr(arr, n);
        break;
      }
      case 3: {
        printf("The last positive elements: %d\n", fnd_lst_pstv(arr, n));
        break;
      }
      case 4: {
        //reads k 
        printf("Enter k here: ");
        while(scanf("%d", &k) != 1 || k>m) {
          printf("Wrong input! The k must be <= max value of the array (%d)!"
                 "\nEnter correct value here: ", m);
          while (getchar()!='\n');
        }

        printf("Number of elements multiple of %d: %lu\n", 
               k, cnt_mltpl_k(arr, n, k));
        break;
      }
      case 5: {
        printf("Number of elements greater than average value of the array: %lu\n", 
               cnt_avg_grt(arr, n));
        break;
      }
    }
    
    // clears buffer from all inputs
    while (getchar()!='\n');

    // continue
    printf("Do you want to continue? (Y/n): ");
    ch=tolower(getchar());
    if (ch=='n') choice=6;
    if (ch!='\n') while (getchar()!='\n');
    putchar('\n');
  } while (choice != 6);
  puts("Done.");

  return 0;
}
