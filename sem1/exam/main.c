# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include <wctype.h> // for iswspace
# include <math.h> // pow
#define N 10 // 1D array size

// task1
int ccw2_10(const wchar_t *wstr, size_t len) {
  int num=0;
  for (size_t i=len-1; i>=0 && 
    !iswspace(*(wstr+i)) && *(wstr+i) != WEOF && 
    (*(wstr+i)==L'0' || *(wstr+i)==L'1'); i--) 
    num += (*(wstr+i) - L'0') * pow(2, i);
  return num;
}

// task2
int sum_odd(int *A, size_t n) {
  int sum=0, num=0;
  for (size_t i=0; i<n; i++) {
    num = *(A+i);
    if (num%2) sum+=num;
  }
  return sum;
}

int main () {
  setlocale(LC_ALL, "");

  // task1
  wchar_t buffer[255] = {0};
  wchar_t ch=0;
  size_t len=0;
  fputws(L"Task #1\nin: ", stdout);
  for (; len<8 && (ch=getwchar())!=WEOF && !iswspace(ch) && 
    (ch==L'0' || ch==L'1'); len++) 
    *(buffer+len)=ch;
  wprintf(L"out: %d\n", ccw2_10(buffer, len));

  // task2 
  int code=0;
  int A[N] = {0};
  fputws(L"\nTask #2\nin: ", stdout);
  for (size_t i=0; i<N; i++)
    while ((code=wscanf(L"%d", (A+i)))!=1) while (!iswspace(ch=getwchar()));
  wprintf(L"out: %d\n", sum_odd(A, N));

  return 0;
}
