#include <stdio.h>

int main() {
  float cups;
  printf("Enter value in cups: ");
  scanf("%f", &cups);
  
  float pint = cups/2;
  float ounce = 8*cups;
  float tab_spn = 2*ounce;
  float tea_spn = 3*tab_spn;

  printf("Value in \n\tpints: %.2f\n\tounces: %.2f\n\ttablespoons: %.2f\n\tteaspoons: %.2f\n", pint, ounce, tab_spn, tea_spn);

  return 0;
}
