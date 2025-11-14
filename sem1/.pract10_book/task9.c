#include <stdio.h>
#include <ctype.h> // tolower
#include <string.h> // strlen

void reverse(char *s) {
  size_t len = strlen(s);
  char tmp;
  for (size_t i=0; i<len/2; i++) {
    tmp=*(s+i);
    *(s+i) = *(s+len-1-i);
    *(s+len-1-i) = tmp;
  }
  *(s+len)='\0';
}

// reads a string and removes \n from the end
void reads(char *s, int n) {
  fgets(s, n, stdin);
  for (int i=0; i<n; i++) if (*(s+i)=='\n') *(s+i) = '\0';
}

int main() {
  char s1[255];
  char choice=0;

  puts("The program reveres a string.\n");
  do {
    fputs("Enter a string here: ", stdout);
    reads(s1, 255);
    
    reverse(s1);
    printf("Reversed string: %s\n", s1);
    
    fputs("Do you want to continue? (Y/n): ", stdout);
    choice = tolower(getchar());
    if (choice != '\n') while (getchar() != '\n');
    if (choice!='n') putchar('\n');
  } while (choice!='n');

  return 0;
}
