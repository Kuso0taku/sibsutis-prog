#include <stdio.h>

unsigned long Fibonacci(unsigned n) {
  if (n <= 2) return 1;
  unsigned c=0;
  //for (unsigned a=1, b=1, i=2; i<n; c=a+b, a=b, b=c, i++);
  for (unsigned a=1, b=1, i=2; i<n; i++) c=a+b,a=b,b=c;
  return c;
}

int main() {
  unsigned n;
  int code;
  
  do {
    printf("Enter a number: ");
    code=scanf("%u", &n);
    printf("Fibonacci(%u) = %lu\n", n, Fibonacci(n));
  } while (code==1);
  printf("Oops! Wrong input!\n");
  
  // a lil test 
  // for (unsigned n=0; n<100000; n++) printf("%lu ", Fibonacci(n));

  return 0;
}
