// THIS PROGRAM DOESN'T COMPARE WITH WINDOWS SYSTEMS

#include <stdio.h>
#include <ctype.h> // tolower()
#include <string.h> // strcmp(), strchr()
#include <unistd.h> // isatty()
#include "matrixfunc.h"

int main() {
  int matrix[COL][ROW] = {0};
  // reads matrix from file's stdin 
  
  // !The isatty() function returns 1 if fildes is associated with a terminal;
  // otherwise it returns 0 and may set errno to indicate the error.

  // 0, 1, 2 is stdin, stdout, stderr
  if (isatty(0) == 0) { // if stdin isn't connected to terminal
    printf("Reading matrix[%d][%d] from stdin...\n", COL, ROW);
    stdin_matrix(matrix); // reads matrix from stdin
    puts("Done.\n");
    freopen("/dev/tty", "r", stdin); // reopen new stdin and close old with EOF
  }
  
  int ch=0, choice=0, code=0, k=0, m=0, l=0;
   do {
    // prints menu
    for (int i=0; i<50; i++) putchar('*');
    putchar('\n');
    puts("(1) Rewrite matrix");
    puts("(2) Print matrix of values with specified indeces");
    puts("(3) Prints indices elements whose values are greater than the k from m column to l");
    puts("(4) Sum of all elements that are multiple of k");
    for (int i=0; i<50; i++) putchar('*');
    putchar('\n');
    
    // reads user choice
    printf("Enter your choice here: ");
    while((code=scanf("%d", &choice)) != 1 || choice<1 || choice>5) {
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
      printf("Wrong input! The input must be a number from 1 to 4!\n"
             "Enter correct value here: ");
    }
    
    // choice processing
    if (choice==5) break;
    switch(choice) {
      case 1: if (input_matrix(matrix)) return EOF; break;
      case 2: stdout_matrix(matrix); break;
      case 3: 
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
      case 4:
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
    if (ch=='n') choice=5;
    if (ch!='\n') 
      while ((ch=getchar())!='\n') 
        if (ch==EOF) {puts("\nError: End-Of-File."); return EOF;}
    putchar('\n');
  } while (choice!=5);
  puts("Done.");
  return 0;
}
