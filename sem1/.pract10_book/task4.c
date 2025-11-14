#include <stdio.h>

int main() {
  int n;
  fputs("Enter a number of max chars in line: ", stdout);
  scanf("%d", &n);
  while (getchar() != '\n'); // clears buffer

  fputs("Enter smth here: ", stdout);
	char word[n+1];
  int ch, count=0;
  while ((ch=getchar()) != '\n' && ch!='\t' && ch!=' ' && count < n) {
    word[count++] = ch;
  }
  word[count]='\0'; // end of string
  printf("The first word: %s\n", word);
  
  return 0;
}
