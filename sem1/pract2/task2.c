#include <stdio.h>

int main() {
  int i = 0;
  printf("Enter symbol in ASCII (int num): ");
  scanf("%d", &i);
  char ch = i;
  printf("Your symbol is %c\n", ch);
  return 0;
}
