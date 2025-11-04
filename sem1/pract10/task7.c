#include <stdio.h>
#include <ctype.h> // tolower

char *mystrncpy(char *s1, char *s2, int n) {
  char *ptr1 = s1;
  char *ptr2 = s2;
  for (int i=0; i<n; i++, ptr1++, ptr2++) {
    *ptr1=*ptr2;
    if (*ptr2=='\0') return s1;
  }
  *ptr1='\0';
  return s1;
}

int main() {
  char s1[255];
  char s2[255];
  int choice=0, n=0;

  while (choice!='n') {
    fputs("Enter a string here: ", stdout);
    fgets(s2, 255, stdin);
    for (int i=0; i<255; i++) s2[i] = (s2[i]=='\n') ? '\0' : s2[i];

    fputs("How many symbols u wanna copy: ", stdout);

    while (scanf("%d", &n)!=1 || n<=0 || n>=255) {
      fputs("Enter a positive number < 255: ", stdout);
      while (getchar() != '\n');} // clears newline

    while (getchar() != '\n');
    for (int i=0; i<n; i++) if (s2[i]=='\n') s2[i] = '\0';

    mystrncpy(s1, s2, n);
    printf("s2 (your string): %s\ns1 (copied string): %s\n", s2, s1);

    fputs("Would u like to continue? (Y/n): ", stdout);
    choice=tolower(getchar());
    if (choice != '\n') while (getchar() != '\n');
    if (choice != 'n') putchar('\n');
  }

  return 0;
}
