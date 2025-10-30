#include <stdio.h>

void to_base_n(unsigned long n, int base) {
  if (!(base>=2 && base<=10)) {
    printf("Base should be from 2 to 10!\n");
    return;
  }
  int r;
  r = n%base;
  if (n >= base) to_base_n(n/base, base);
  putchar(r+'0');
  return;
}

int main() {
  unsigned long n;
  int base, code;
  do {
    printf("Enter number and base (from 2 to 10) of cc: ");
    code=scanf("%lu%d", &n, &base);
    if (code==2) {
      printf("%lu in %dcc: ", n, base);
      to_base_n(n, base);
      putchar('\n');
    }
  } while (code==2);

  return 0;
}
