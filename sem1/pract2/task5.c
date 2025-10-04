#include <stdio.h>

int main() {
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);

  float age_s = 3.156e7f * age;
  printf("Your age in seconds: %.2f", age_s);

  return 0;
}
