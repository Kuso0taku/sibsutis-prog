#include <stdio.h>

#define INCH 2.54
#define FOOT 30.48

int main() {
  float cm;
  printf("Enter height in centimeters: ");
  scanf("%f", &cm);
  printf("%.1f cm = %d foots, %.1f inches\n", cm, (int)(cm/FOOT), cm/INCH);
  while (cm > 0) {
    printf("Enter height in centimeters (<=0 for exit from the program): ");
    scanf("%f", &cm);
    if (cm > 0) {printf("%.1f cm = %d foots, %.1f inches\n", cm, (int)(cm/FOOT), cm/INCH);}
  }
  printf("Work completed.\n");

  return 0;
}
