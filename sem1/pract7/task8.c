#include <stdio.h>

double power(double a, int n) {
  if (a==0 && n==0) {printf("Error: 0^0 is not defined!\n"); return 1;}
  if (a==0) return 0;
  if (n==0) return 1;
  double res=a;
  if (n>0) for (int i=0; i<n; i++) res*=a;
  else for (int i=0; i<n; i++) res*=1/a;
  return res;
}

int main() {
  double a;
  int n, code0, code1;
  printf("The program pows a double number.\n");
  for (int i=0; i<25; i++) putchar('-'); 
  putchar('\n');
  do {
    printf("Enter a number to pow: ");
    code0 = scanf("%lf", &a);
    printf("Enter a power: ");
    if (code0==1 && (code1=scanf("%d", &n))==1)
    printf("(%.2lf)^%d=%.2lf\n", a, n, power(a,n));
    for (int i=0; i<25; i++) putchar('-'); 
    putchar('\n');
  } while (code0==1 && code1==1);
  printf("Oops! Wrong input!\n");
  return 0;
}
