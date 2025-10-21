#include <stdio.h>
#define SALARY 10'000 // per hour
#define RATIO 1.5
#define HOURS 40
#define TAXRATIO1 0.15
#define TAXRATIO2 0.2
#define TAXRATIO3 0.25
#define TAXFOR1 300
#define TAXFOR2 150
#define TAX1 TAXFOR1 * TAXRATIO1
#define TAX2 TAXFOR2 * TAXRATIO2

int main() {
  int h; // hours
  printf("Enter how many hours you've worked: ");
  scanf("%d", &h);

  int over_h = (h>HOURS) ? (h-HOURS) : 0;
  float amount = over_h*RATIO*SALARY + (h-over_h)*SALARY;

  float tax=0;
  if (amount <= TAXFOR1) {tax = amount * TAXRATIO1;}
  else if (amount <= TAXFOR1+TAXFOR2) {
    tax = TAX1 + (amount - TAXFOR1) * TAXRATIO2;
  } else {tax = TAX1 + TAX2 + (amount-TAXFOR1-TAXFOR2)*TAXRATIO3;}
  float salary = amount - tax;
  
  printf("Total amount of charges: $%.2f\n", amount);
  printf("\t$tax: %.2f\n\tnet salary: $%.2f\n", tax, salary);
  
  return 0;
}
