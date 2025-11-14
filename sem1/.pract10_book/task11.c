#include <stdio.h>
#include <string.h> // strcpy, strcmp
#define N 10 // max strings in array
#define SIZE 255 // max size of string

// prints all strings from array
void print_sarr(char sarr[N][SIZE]) {
  for (int i=0; i<N; i++) fputs(sarr[i], stdout);
}

// ascending strings by ascii
void asc(char sarr0[N][SIZE]) {
  char sarr[N][SIZE];
  char temp[SIZE];
  for (int i=0; i<N; i++) strcpy(sarr[i], sarr0[i]);
  
  for (int i=0; i<N-1; i++) {
    for (int j=0; j<N-1; j++) {
      if (strcmp(sarr[j], sarr[j+1]) > 0) {
        strcpy(temp, sarr[j]);
        strcpy(sarr[j], sarr[j+1]);
        strcpy(sarr[j+1], temp);
      }
    }
  }
  
  print_sarr(sarr);
}

// ascending by length
void asc_len(char sarr0[N][SIZE]) {
  char sarr[N][SIZE] = {0};
  char temp[SIZE];
  for (int i=0; i<N; i++) strcpy(sarr[i], sarr0[i]);
  
  for (int i=0; i<N-1; i++) {
    for (int j=0; j<N-1; j++) {
      if (strlen(sarr[j]) > strlen(sarr[j+1])) {
        strcpy(temp, sarr[j]);
        strcpy(sarr[j], sarr[j+1]);
        strcpy(sarr[j+1], temp);
      }
    }
  }
  
  print_sarr(sarr);
}

// returns length of first word in string
int len_wrd(char *s) {
  int count=0;
  for (int i=0; i<SIZE; i++) {
    if (*(s+i) != ' ' && *(s+i) != '\n' && *(s+i) != '\t' && *(s+i) != EOF)
      count ++;
    else break;
  }
  return count;
}

// ascending by length of the first word
void asc_len_w(char sarr0[N][SIZE]) {
  char sarr[N][SIZE];
  char temp[SIZE];
  for (int i=0; i<N; i++) strcpy(sarr[i], sarr0[i]);
  
  for (int i=0; i<N-1; i++) {
    for (int j=0; j<N-1; j++) {
      if (len_wrd(sarr[j]) > len_wrd(sarr[j+1])) {
        strcpy(temp, sarr[j]);
        strcpy(sarr[j], sarr[j+1]);
        strcpy(sarr[j+1], temp);
      }
    }
  }
  
  print_sarr(sarr);
}

// input array of strings
void input_sarr(char sarr[N][SIZE]) {
  char ch;
  int j=0;
  for (int i=0; i<N; i++) {
    for (j=0; j<SIZE; j++) {
      ch=getchar();
      // clearerr resets errors and EOF
      if (ch == EOF) {clearerr(stdin); break;}
      sarr[i][j] = ch;
      if (ch == '\n') {j++; break;}
    }
    sarr[i][j] = '\0';
    if (ch == EOF) break;
  }
}

// just prints stars
void stars(int n) {
  for (int i=0; i<n; i++) putchar('*');
  putchar('\n');
}

// prints menu
void menu() {
  const short n=50;
  stars(n);
  puts("1) output the initial list of strings\n" 
       "2) output the strings according to the ASCII comparison sequence\n"
       "3) output the strings in ascending order of length\n"
       "4) output the strings in ascending order of the length of the"
          "first word in the string\n"
       "5) exit the program");
  stars(n);
}

int main () {
  char strings[N][SIZE] = {0};
  int choice=0, code=0;
  
  puts("To start enter strings below. Max numbers of string is 10.\n"
       "You can also enter EOF (^D in linux && ^Z in windows) "
       "to stop entering strings earlier\n");

  input_sarr(strings);
  putchar('\n');

  while (choice!=5) {
    menu();
    do {
      fputs("Enter a number from 1 to 5: ", stdout);
      code = scanf("%d", &choice);
      while (getchar() != '\n'); // clears buffer
    } while (code != 1 || choice<1 || choice>5);
    putchar('\n');
    switch (choice) {
      case 1: print_sarr(strings); break;
      case 2: asc(strings); break;
      case 3: asc_len(strings); break;
      case 4: asc_len_w(strings); break;
      case 5: puts("Thanks for using my program!");
    }
  }

  return 0;
}
