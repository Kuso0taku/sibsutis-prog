#include <stdio.h>
#include <ctype.h> // tolower()
#include "myarrfunc.h"

int main() {
  int choice=0, k=0, ch=0, m=0, code=0;
  do {
    // init size of array
    int n=0;
    printf("Enter array length: ");
    while((code=scanf("%d", &n)) != 1 || n<=0) {
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
      printf("Wrong input! The num must be >= 0! Enter correct value here: ");
    }
  
    // init array
    int arr[n];
    for (int i=0; i<n; i++) {
      printf("Enter the %d element: ", i+1);
      while((code=scanf("%d", arr+i)) != 1) {
        while ((ch=getchar())!='\n') 
          if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
        printf("Wrong input! Enter correct value here: ");
      }
    }
  
    putchar('\n');
    m=fnd_max(arr, n);
    // prints menu
    for (int i=0; i<35; i++) putchar('*');
    putchar('\n');
    puts("(1) Print values of array elements");
    puts("(2) Print addresses of array elements");
    puts("(3) Print (value, address) of array elements");
    puts("(4) Find last positive element");
    puts("(5) Count elements multiple of k");
    puts("(6) Count elements greater than average value of the array");
    puts("(7) Exit");
    for (int i=0; i<35; i++) putchar('*');
    putchar('\n');

    // reads choice
    printf("Enter your choice: ");
    while((code=scanf("%d", &choice)) != 1 || choice<1 || choice>7) {
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
      printf("Wrong input! The input must be a number from 1 to 7!\n"
             "Enter correct value here: ");
    }
    
    // choice processing
    if (choice==7) break;
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
        print_arr_vp(arr, n);
        break;
      }
      case 4: {
        printf("The last positive elements: %d\n", fnd_lst_pstv(arr, n));
        break;
      }
      case 5: {
        //reads k 
        printf("Enter k here: ");
        while((code=scanf("%d", &k)) != 1 || k>m) {
          while ((ch=getchar())!='\n') 
            if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
          printf("Wrong input! The k must be <= max value of the array (%d)!"
                 "\nEnter correct value here: ", m);
        }

        printf("Number of elements multiple of %d: %lu\n", 
               k, cnt_mltpl_k(arr, n, k));
        break;
      }
      case 6: {
        printf("Number of elements greater than average value of the array: %lu\n", 
               cnt_avg_grt(arr, n));
        break;
      }
    }
    
    // clears buffer from all inputs
    while ((ch=getchar())!='\n') if (ch==EOF) break;

    // continue
    printf("Do you want to continue? (Y/n): ");
    ch=tolower(getchar());
    if (ch=='n') choice=7;
    if (ch!='\n') 
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
    putchar('\n');
  } while (choice != 7);
  puts("Done.");

  return 0;
}
