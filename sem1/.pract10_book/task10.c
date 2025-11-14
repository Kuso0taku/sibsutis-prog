#include <stdio.h>
#include <string.h> // strlen

void rm_spc(char *s) {
  size_t len = strlen(s);
  size_t j=0;
  for (size_t i=0; i<len; i++) {
    if (*(s+i) != ' ') {
      *(s+j)=*(s+i);
      j++;
    }
  }
  *(s+j) = '\0';
}

// reads a string and removes \n from the end
void reads(char *s, int n) {
  fgets(s, n, stdin);
  for (int i=0; i<n; i++) if (*(s+i)=='\n') *(s+i) = '\0';
}

int main() {
  char s1[255];

  puts("The program deletes spaces from string.\n(enter nothing to exit)\n");
  do {
    fputs("Enter a string here: ", stdout);
    reads(s1, 255);
    if (*s1 != '\0') {
      rm_spc(s1);
      printf("New string: %s\n\n", s1);
    }
  } while (*s1 != '\0');

  return 0;
}
