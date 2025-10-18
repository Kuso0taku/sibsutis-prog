#include <stdio.h>

int main() {
  char usr_ch;
  printf("Enter a character to make a triangle to it: ");
  scanf("%c", &usr_ch);
  int rows = (int)usr_ch%'A';
  for (int i=0;i<=rows;i++) {
    char ch='A';
    // spaces
    for (int j=0;j<rows-i;j++) {printf(" ");}
    // letters
    for (int j=0;j<i;j++) {printf("%c", ch++);}
    // letters reversed
    for (int j=0;j<=i;j++) {printf("%c", ch--);}
    // spaces
    for (int j=0;j<rows-i;j++) {printf(" ");}
    printf("\n");
  }
  
  return 0;
}
