#include <stdio.h>
#include <string.h> // for strlen only

int main() {
  char name[255];
  char surname[255];
  printf("Enter your name and surname: ");
  scanf("%s%s", name, surname);
  int l_name = (int)strlen(name);
  int l_surname = (int)strlen(surname);
  
  printf("%s %s\n%*d %*d\n", 
         name, surname, l_name, l_name, l_surname, l_surname);

  printf("%s %s\n%-*d %-*d\n", 
         name, surname, l_name, l_name, l_surname, l_surname);

  return 0;
}
