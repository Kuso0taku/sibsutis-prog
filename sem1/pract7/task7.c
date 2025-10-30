#include <stdio.h>
#include <ctype.h> // isalpha, tolower

int main() {
  char ch;
  printf("Enter smth here 'til end of file: ");
  while ((ch=getchar())!=EOF) {
    ch=tolower(ch);
    switch (ch) {
      case '\n':
        printf("'\\n'");
        break;
      case '\t':
        printf("'\\t'");
        break;
      default:
        printf("'%c'", ch);
    }
    putchar('=');
    if (isalpha(ch)) printf("%d ", ch-'a'+1);
    else printf("%d ", -1);
  }
}
