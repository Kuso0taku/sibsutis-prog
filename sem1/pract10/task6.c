#include <stdio.h>
#include <ctype.h>

_Bool is_within(char ch, char *str) {
  while (*str != '\0') {
    if (*str == ch) return 1;
    str++;}
  return 0;
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
    printf("The result of the program: %d\n", is_within(ch, string));
    fputs("Would you like to continue? (Y/n) ", stdout);
    choice = tolower(getchar());
  } while (choice != 'n');
  return 0;
}
