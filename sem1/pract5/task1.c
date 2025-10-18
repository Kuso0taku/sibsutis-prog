#include <stdio.h>

int main() {
  // (char)97 is 'a' 
  char ch = 97;
  char arr[26];
  for (int i=0;i<26;i++) {arr[i]=ch++;}
  for (int i=0;i<26;i++) {printf("%c", arr[i]);}

  return 0;
}
