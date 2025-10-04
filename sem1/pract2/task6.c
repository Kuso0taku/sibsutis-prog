#include <stdio.h>

int main() {
  int qrts;
  printf("Enter a volume of water (in quarts): ");
  scanf("%d", &qrts);
  float mlcls = qrts*950 / 3.0e-23;
  printf("Number of molecules in %d quarts: %.2e\n", qrts, mlcls);

  return 0;
}
