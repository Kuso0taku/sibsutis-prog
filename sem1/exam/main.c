# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include <wctype.h> // for iswspace
# include <math.h> // pow

int ccw2_10(const wchar_t *wstr, size_t len) {
  int num=0;
  for (size_t i=len-1; i>=0 && 
    !iswspace(*(wstr+i)) && *(wstr+i) != WEOF && 
    (*(wstr+i)==L'0' || *(wstr+i)==L'1'); i--) 
    num += (*(wstr+i) - L'0') * pow(2, i);
  return num;
}

int main () {
  setlocale(LC_ALL, "");

  // input task1
  wchar_t buffer[255] = {0};
  wchar_t ch=0;
  size_t len=0;
  fputws(L"Task #1\nin: ", stdout);
  for (; len<8 && (ch=getwchar())!=WEOF && !iswspace(ch) && 
    (ch==L'0' || ch==L'1'); len++) 
    *(buffer+len)=ch;
  wprintf(L"out: %d\n", ccw2_10(buffer, len));
  
  return 0;
}
