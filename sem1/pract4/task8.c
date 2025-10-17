#include <stdio.h>

int main() {
  printf("This program calculates the results of modulo division.\n");
  int operand1, operand2;
  printf("Enter an integer to serve as the second operand: ");
  scanf("%d", &operand2);
  printf("Now enter the first operand: ");
  scanf("%d", &operand1);
  printf("%d %% %d equals %d\n", operand1, operand2, operand1%operand2);
  while (operand1 > 0 && operand2 > 0) {
    printf("Now enter the first operand (<= 0 for exit from program): ");
    scanf("%d", &operand1);
    if (operand1 > 0 && operand2 > 0)
    {printf("%d %% %d equals %d\n", operand1, operand2, operand1%operand2);}
  }
  printf("Done.\n");
  return 0;
}
