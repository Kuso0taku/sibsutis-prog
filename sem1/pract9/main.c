#include <stdio.h>
#include <ctype.h> // tolower()
#include "matrixfunc.h"

int main() {
  int matrix[COL][ROW] = {0};
  printf("Reading matrix[%d][%d] from stdin...\n", COL, ROW);
  stdin_matrix(matrix); // reads matrix from stdin
  puts("Done.\n");
  freopen("/dev/tty", "r", stdin); // reopen new stdin and close old with EOF
  
  int ch=0, choice=0, code=0, k=0, m=0, l=0;
   do {
    // prints menu
    for (int i=0; i<50; i++) putchar('*');
    putchar('\n');
    puts("(1) Print matrix of values with specified indeces");
    puts("(2) Prints indices elements whose values are greater than the k from m column to l");
    puts("(3) Sum of all elements that are multiple of k");
    for (int i=0; i<50; i++) putchar('*');
    putchar('\n');
    
    // reads user choice
    printf("Enter your choice here: ");
    while((code=scanf("%d", &choice)) != 1 || choice<1 || choice>4) {
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
      printf("Wrong input! The input must be a number from 1 to 3!\n"
             "Enter correct value here: ");
    }
    
    // choice processing
    if (choice==4) break;
    switch(choice) {
      case 1: stdout_matrix(matrix); break;
      case 2: 
        // reads k
        printf("Enter k here: ");
        while((code=scanf("%d", &k)) != 1) {
          while ((ch=getchar())!='\n') 
            if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
          printf("Wrong input! k must be an int!\n"
                 "Enter correct value here: ");
        }
        // reads m, l
        printf("Enter m, l: ");
        while((code=scanf("%d%d", &m, &l)) != 2 || m>l) {
          while ((ch=getchar())!='\n') 
            if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
          printf("Wrong input! l, m must be an int and l<=m!\n"
                 "Enter correct value here: ");
        }
        find_grtrk_m_l(matrix, k, m, l);
        break;
      case 3:
        // reads k
        printf("Enter k here: ");
        while((code=scanf("%d", &k)) != 1) {
          while ((ch=getchar())!='\n') 
            if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
          printf("Wrong input! k must be an int!\n"
                 "Enter correct value here: ");
        }
        printf("Sum of elements multiple %d: %d\n", k, sum_mltk(matrix, k));
        break;
    }
    // clears buffer from all inputs
    while (getchar()!='\n');

    // continue
    printf("Do you want to continue? (Y/n): ");
    ch=tolower(getchar());
    if (ch=='n') choice=4;
    if (ch!='\n') 
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
    putchar('\n');
  } while (choice!=4);
  puts("Done.");
  return 0;
}
