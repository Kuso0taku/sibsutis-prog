#include <stdio.h>
#define LITER 3.785
#define KM 1.609

int main() {
  float distance, fuel;
  printf("Enter the distance traveled in miles: ");
  scanf("%f", &distance);
  printf("Enter the volume of gasoline consumed in gallons: ");
  scanf("%f", &fuel);
  // fuel consumption
  float us_cons = distance/fuel;
  printf("Miles traveled per gallon: %.1f (mph)\n", us_cons);
  float eu_cons = fuel*LITER/distance/KM*100;
  printf("Liters consumed per 100 kilometers: %.1f (l/100km)\n", eu_cons);

  return 0;
}
