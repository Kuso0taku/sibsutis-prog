#include <stdio.h>
#include <ctype.h> // isdigit
#include <string.h> // strlen
#include <math.h> // pow

int atoi(char* arg) {
  char *p = arg;
  size_t len = strlen(arg);
  int n=0;
  for (int i=pow(10, len-1); i>0; i/=10, p++) {
    if (!isdigit(*p)) return 0;
    n += (*p-'0')*i;
  }
  return n;
}

int main(int argc, char** argv) {
  printf("atoi of first argument: %d\n", atoi(argv[1]));

  return 0;
}
