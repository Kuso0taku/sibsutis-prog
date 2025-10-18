#include <stdio.h>

int main() {
  int up, low;
  printf("Enter lower limit of table: ");
  scanf("%d", &low);
  printf("Enter upper limit of table: ");
  scanf("%d", &up);
  int cell_size = 10;

  printf("\n");
  for (int i=low;i<=up;i++) {
    printf("%-*d %-*d %-*d", 
           cell_size, i, cell_size, i*i, cell_size, i*i*i);
    printf("\n");
  }
   
  return 0;
}
