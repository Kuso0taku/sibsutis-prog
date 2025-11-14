#include <stdio.h>
#include <ctype.h>

int main() {
  int cnt_w=0, cnt_up=0, cnt_low=0, cnt_pnc=0, cnt_dgt=0;
  char ch;
  puts("Enter smth below (end of file to exit):");
  while ((ch=getchar()) != EOF) {
    if (isdigit(ch)) cnt_dgt++;
    else if (islower(ch)) cnt_low++;
    else if (isupper(ch)) cnt_up++;
    else if (ispunct(ch)) cnt_pnc++;
    else if (isspace(ch)) cnt_w++;
  }
  printf("Number of:\n\twords: %d\n\tuppercase: %d\n\tlowercase: %d\n\t\
punctuations: %d\n\tdigits: %d\n", cnt_w, cnt_up, cnt_low, cnt_pnc, cnt_dgt);
}
