#include <stdio.h>
#define SALARY 10'000 // per hour
#define RATIO 1.5
#define HOURS 40
#define TARIFF1 8.75
#define TARIFF2 9.23
#define TARIFF3 10.0
#define TARIFF4 11.2
#define TAXRATIO1 0.15
#define TAXRATIO2 0.2
#define TAXRATIO3 0.25
#define TAXFOR1 300
#define TAXFOR2 150
#define TAX1 TAXFOR1 * TAXRATIO1
#define TAX2 TAXFOR2 * TAXRATIO2

void program(float tariff) {
  int h; // hours
  printf("Enter how many hours you've worked: ");
  scanf("%d", &h);

  int over_h = (h>HOURS) ? (h-HOURS) : 0;
  float amount = over_h*RATIO*tariff + (h-over_h)*tariff;

  float tax=0;
  if (amount <= TAXFOR1) {tax = amount * TAXRATIO1;}
  else if (amount <= TAXFOR1+TAXFOR2) {
    tax = TAX1 + (amount - TAXFOR1) * TAXRATIO2;
  } else {tax = TAX1 + TAX2 + (amount-TAXFOR1-TAXFOR2)*TAXRATIO3;}
  float salary = amount - tax;
  
  printf("Total amount of charges: $%.2f\n", amount);
  printf("\ttax: $%.2f\n\tnet salary: $%.2f\n", tax, salary);
}

int main() {
  int choice;
  do { 
    for (int i=0; i<60; i++) {printf("*");}
    printf("\n");
    printf("Enter number corresponding to desired tariff rate or action:\n");
    printf("1) $%.2f/h\t\t\t2) $%.2f/h\n3) $%.2f/h\t\t\t4) $%.2f/h\n5) Exit\n",
           TARIFF1, TARIFF2, TARIFF3, TARIFF4);
    for (int i=0; i<60; i++) {printf("*");}
    printf("\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1: program(TARIFF1); break;
      case 2: program(TARIFF2); break;
      case 3: program(TARIFF3); break;
      case 4: program(TARIFF4); break;
      default: continue;
    }
  } while (!(choice >= 1 && choice <= 5));
    
  return 0;
}
