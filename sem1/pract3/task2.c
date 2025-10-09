#include <stdio.h>
#include <string.h> // for strlen only

int main(void) {
  char name[255];
  printf("Enter your name here: ");
  scanf("%s", name);
  // a)
  printf("a) \"%s\"\n", name);
  // б) 20 is right align and 20 symbols len of line
  printf("б) \"%20s\"\n", name);
  // в) - is left align like default 
  printf("в) \"%-20s\"\n", name);
  // г) * in %*s gets an int number
  printf("г) \"%-*s\"\n", (int)strlen(name)+3, name);

  return 0;
}
