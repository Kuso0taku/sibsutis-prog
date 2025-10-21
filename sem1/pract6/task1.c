#include <stdio.h>
#define SPACE ' '
#define NEWLINE '\n'

int main() {
  unsigned short n_spc=0, n_nline=0, n_other=0;
  char ch;
  printf("Enter smth here ('#' to exit):\n");
  while ((ch = getchar()) != '#') {
    switch (ch) {
      case SPACE:
        n_spc++;
        break;
      case NEWLINE:
        n_nline++;
        break;
      default:
        n_other++;
    }
  }
  printf("Number of\n\tspaces: %hu\n\tnewlines: %hu\n\tother: %hu\n",
         n_spc, n_nline, n_other);
  
  return 0;
}
