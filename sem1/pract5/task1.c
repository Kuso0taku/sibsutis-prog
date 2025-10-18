#include <stdio.h>

int main() {
  char ch = 'a';
  char arr[26];
  for (int i=0;i<26;i++) {arr[i]=ch++;}
  for (int i=0;i<26;i++) {printf("%c", arr[i]);}

  return 0;
}
