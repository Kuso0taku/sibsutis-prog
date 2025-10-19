#include <stdio.h>

float calc(float x, float y) {return (x-y)/(x*y);}

int main() {
  float x,y;
  int code;
  do {
    printf("Enter two float numbers (q to exit): ");
    code = scanf("%f%f", &x,&y);
    if (code) printf("(x-y)/(x*y) = %f\n", calc(x, y));
  } while (code);
  printf("Done.\n");
  
  return 0;
}
