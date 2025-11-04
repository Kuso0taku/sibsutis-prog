#include <stdio.h>
#include <ctype.h>

char *my_strchr(char *str, char ch) {
  while (*str != '\0') {
    if (*str == ch) return (char *)str;
    str++;}
  return NULL;
}

int main() {
  char string[255];
  char ch=0, choice;
  do {
    fputs("Enter a string: ", stdout);
    fgets(string, 255, stdin);
    fputs("Enter a char: ", stdout);
    ch = getchar();
    while (getchar() != '\n');
    printf("The result of program: %p\n", my_strchr(string, ch));
    fputs("Would you like to continue? (Y/n) ", stdout);
    choice = tolower(getchar());
  } while (choice != 'n');
  return 0;
}
