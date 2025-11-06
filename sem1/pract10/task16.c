#include <stdio.h>
#include <string.h> // strcmp, strlen
#include <ctype.h> // tolower, toupper

int main(int argc, char **argv) {
  char ch;
  while ((ch=getchar()) != EOF) {
    if (!strcmp(argv[1], "-p") || ('-' != argv[1][0] && strlen(argv[1])))
      putchar(ch);
    else if (!strcmp(argv[1], "-u")) putchar(toupper(ch));
    else if (!strcmp(argv[1], "-l")) putchar(tolower(ch));
  }

  return 0;
}
