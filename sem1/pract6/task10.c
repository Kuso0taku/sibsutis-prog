#include <stdio.h>

#define ALONE 17'850
#define HEAD 23'900 // of family
#define JOINT 29'750 // married, joint farming
#define SEPARATED 14'875 // married, separated farming
#define RATIO1 0.15
#define RATIO2 0.28

int main() {
  int salary;
  printf("Enter your salary before taxes: ");
  scanf("%d", &salary);
  
  int code;
  do {
    for (int i=0; i<70; i++) {printf("-");}
    printf("\n");
    printf("Choose your category (enter 'q' to exit):\n");
    printf("1) Alone\t\t2)Head of family\n");
    printf("3) Married, joint farming\t4) Married, separated farming\n");
    for (int i=0; i<70; i++) {printf("-");}
    printf("\n");
    int choice=0;
    code = scanf("%d", &choice);
    
    int first; // 15% tax from first, for example, $10'000
    switch (choice) {
      case 1: first = ALONE; break;
      case 2: first = HEAD; break;
      case 3: first = JOINT; break;
      case 4: first = SEPARATED; break;
      default: continue;
    }
    float tax = 0;
    if (salary <= first) {tax += RATIO1*salary;}
    else {tax += RATIO1*first + RATIO2*(salary-first);}

    printf("Your tax is $%.2f\n\n", tax);
  } while (code);

  return 0;
}
