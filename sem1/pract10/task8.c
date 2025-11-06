#include <stdio.h>
#include <ctype.h> // for tolower

char *string_in(char *s1, char *s2) {
  if (*s2 == '\0') return s1;

  while (*s1 != '\0') {
    char *p1 = s1;
    char *p2 = s2;

    while (*p1 == *p2 && *p1 != '\0') {p1++; p2++;}
    if (*p2 == '\0') return s1;

    s1++;
  }
  return NULL;
}

// reads a string and removes \n from the end
void reads(char *s, int n) {
  fgets(s, n, stdin);
  for (int i=0; i<n; i++) if (*(s+i)=='\n') *(s+i) = '\0';
}

int main() {
  char s1[255];
  char s2[255];
  puts("The program finds substring in string. " 
       "If found returns address of first substring element in string "
       "else returns NULL.\n");
  char choice=0;
  do {
    fputs("Enter a string here: ", stdout);
    reads(s1, 255);
    fputs("Enter substring here: ", stdout);
    reads(s2, 255);

    char *res = string_in(s1, s2);
    if (res) printf("Symbol %c at %lu position in %p\n", *res, res-s1, res);
    else puts("String doesn't include substring");
    
    fputs("Do you want to continue? (Y/n): ", stdout);
    choice = tolower(getchar());
    if (choice != '\n') while (getchar() != '\n');
    if (choice!='n') putchar('\n');
  } while (choice!='n');

  return 0;
}
