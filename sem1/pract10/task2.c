#include <stdio.h>

int main() {
  int n;
  fputs("Enter how many symbols u'd like to read: ", stdout);
  scanf("%d", &n);
  while (getchar() != '\n'); // to clear the buffer

  fputs("Enter smth here: ", stdout);
  char line[n+1]; // for '\0'
  fgets(line, n+1, stdin);
  // ends string when meets '\n', '\t' or ' '
  for (int i=0; i<n+1; i++) 
    line[i] = (line[i] == '\n' || line[i] == '\t' || line[i] == ' ') ? '\0' : line[i];

  fputs("Your line: ", stdout);
  puts(line);
  return 0;
}
