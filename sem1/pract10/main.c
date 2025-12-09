#include "stringfunc.h"
#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  
  if (argc != 2 && argc != 6 ||
    (cmp(argv[1], "1") && cmp(argv[1], "2") &&
    cmp(argv[1], "3") && cmp(argv[1], "4")) ||
    (argc==6 && (cmp(argv[2], "<") || cmp(argv[4], ">"))))
  {
    fputws(L"Commands:\n", stdout);
    fputws(L"\t 1 - count how many every character\n", stdout);
    fputws(L"\t 2 - inserts exclemation mark in the end of lines\n", stdout);
    fputws(L"\t 3 - finds and counts words with dashes\n", stdout);
    fputws(L"\t 4 - inserts 'с' after vowel and repeats vowel\n", stdout);
    fputws(L"\nUsage:\n\t./program 1 < in > out\n\tor\n\t./program 1\n", stdout);
    return 1;
  }

  // read input
  wchar_t buffer[BUFFER_SIZE] = {0};
  for (size_t i=0; i<BUFFER_SIZE; i++) {
    *(buffer+i) = getwchar();
    if (*(buffer+i) == WEOF) *(buffer+i) = L'\0';
  }
  *(buffer+BUFFER_SIZE-1)=L'\0';
  
  switch (argv[1][0]) {
    // count how many every character
    case '1': cnt_chs(buffer); break;
    // inserts exclemation mark in the end of lines
    case '2': ins_exclm_mark(buffer); break;
    // finds and counts words with dashes
    case '3': cnt_dash_wrds(buffer); break;
    // inserts 'с' after vowel and repeats vowel
    case '4': ins_c_after_vwl(buffer); break;
  }

  return 0;
}
