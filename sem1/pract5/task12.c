#include <stdio.h>

double calc(int limit, _Bool sign) {
  double sum=0;
  for (int i=1;i<=limit;i++) {
    if (sign) {sum += 1.0/i;}
    else {sum += ((i%2) ? 1 : -1)*(1.0/i);}
  }
  return sum;
}

int main() {
  int limit;
  do {
    printf("Enter a limit of sequences (<=0 to exit): ");
    scanf("%d", &limit);
    if (limit>0) {
      printf("Result of\n\
\tPositive sequence: %lf\n\tAlternating sequence: %lf\n", 
             calc(limit, 1), calc(limit, 0));
    }
  } while (limit>0);
  
  return 0;
}
