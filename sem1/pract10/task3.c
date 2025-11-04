#include <stdio.h>

int main() {
	char word[255];
  char *ptr = word;
  fputs("Enter smth here: ", stdout);
  char ch;
  while ((ch=getchar()) != '\n' && ch!='\t' && ch!=' ') {
    *ptr++ = ch;
  }
  *ptr='\0'; // end of string
  printf("The first word: %s\n", word);
	return 0;
}
