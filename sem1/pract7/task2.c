#include <stdio.h>

void chline(char ch, int i, int j) {
  for (int k=0;k<i;k++) {printf(" ");}
  for (;i<j;i++) {printf("%c", ch);}
  printf("\n");
}

int main() {
  int code;
  char ch;
  int i,j;
  do {
    printf("Enter a char here: ");
    code = scanf(" %c", &ch);
    printf("Enter a char and 2 int numbers here: ");
    if (code==1) {code += scanf("%d%d", &i, &j);}
    else {break;}
    if (code==3) {
      printf("The result line is:\n");
      chline(ch, i, j);
      printf("\n");
    }
  } while (code == 3);
  printf("\nOops! Wrong input!\n");


  return 0;
}
