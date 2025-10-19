#include <stdio.h>

int sum(int x, int y) {
  int sum=0;
  for (;x<=y;x++) {sum += x*x;}
  return sum;
}

int main() {
  int low,up;
  printf("Enter lower and upper int limits: ");
  scanf("%d%d", &low, &up);

  while (up > low) {
    printf("Sum of squares int numbers from %d to %d equals %d\n",
           low*low, up*up, sum(low, up));
    printf("Enter next combinations of limits: ");
    scanf("%d%d", &low, &up);

  };
  printf("Work completed\n");
  
  return 0;
}
