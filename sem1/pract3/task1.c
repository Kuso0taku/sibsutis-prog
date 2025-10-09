#include <stdio.h>

int main(void) {
  // guess the longest name user can enter
  char name[255];
  printf("Enter your name 'n surname, please: ");
  
  // %[set] is modification of %s so we don't need to write %[set]s
  // ^ exclude symbol(s) in the string
  // [^\n] means scanf stops input when user enters \n
  scanf("%[^\n]", name); // but \n stuck in buffer so we have to clear it
  // to remove \n from buffer we can getchar() without init any variable
  // getchar(); // removes char from buffer

  // or we can use this to do same:
  // fgets(name, 255, stdin); // but fgets also reads \n symbol

  printf("Hi, %s!\n", name);
  return 0;
}
