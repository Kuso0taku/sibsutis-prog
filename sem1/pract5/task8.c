#include <stdio.h>

int main() {
  float x,y;
  int code;
  do {
    printf("Enter two float numbers (q to exit): ");
    code = scanf("%f%f", &x,&y);
    if (code) printf("(x-y)/(x*y) = %f\n", (x-y)/(x*y));
  } while (code);
  printf("Done.\n");
  
  return 0;
}
