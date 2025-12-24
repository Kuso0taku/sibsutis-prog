# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include <wctype.h> // for iswspace, towlower
# include <math.h> // pow
#define N 10 // 1D array size
#define M 6 // 2D array size
#define BUF_SIZE 255

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

// task3
wchar_t *rmwvowel(wchar_t *wstr, size_t len) {
  wchar_t wch=0;
  size_t cnt=0;
  for (size_t i=0; i<len && *(wstr+i)!=WEOF && *(wstr+i)!=L'\0'; i++) {
    wch = *(wstr+i);
    if (towlower(wch) != L'a' && towlower(wch) != L'e' && towlower(wch) != L'u' &&
        towlower(wch) != L'o' && towlower(wch) != L'i')
      *(wstr+cnt++) = wch;
  }
  if (cnt>=len) cnt--;
  *(wstr+cnt) = L'\0';
  return wstr;
}

// task4
size_t min_suffix(wchar_t *wstr, size_t len) {
  wchar_t wch=0;
  size_t min=BUF_SIZE, cnt=-1;
  _Bool f=0; // flag if L'.' was found
  for (size_t i=0; i<len && *(wstr+i)!=WEOF && *(wstr+i)!=L'\0'; i++) {
    wch = *(wstr+i);
    if (wch == L'.') f=1;
    else if (iswspace(wch)) {f=0; min = (min>cnt && cnt>0) ? cnt : min; cnt=-1;}
    if (f) cnt++;
  }
  if (min==BUF_SIZE) return 0;
  return min;
}

// task5
size_t max_asc_seq(wchar_t *wstr, size_t len) {
  if (len==0) return 0;
  wchar_t wchs=0, wche=0; // start and end wide-chars
  size_t max=1, cnt=1;
  for (size_t i=0; i<len && *(wstr+i)!=WEOF && *(wstr+i)!=L'\0'; i++) {
    wchs = *(wstr+i);
    for (size_t j=i+i; j<len && *(wstr+j)!=WEOF && *(wstr+j)!=L'\0'; j++) {
      wche = *(wstr+j);
      if (wche <= wchs) cnt++;
      else max = (max<cnt && cnt>0) ? cnt : max;
    }
    cnt=1;
  }
  if (max==BUF_SIZE) return 1;
  return max;
}

// task6 
void arr_spiral(int A[M][M], size_t n, size_t m) {
  size_t top=0, bottom = n-1;
  size_t left=0, right = m-1;
  int code=0;
  wchar_t ch=0;
  while (top<=bottom && left<=right) {
    for (size_t i=left; i<=right; i++) {
      while ((code=wscanf(L"%d", *(A+top)+i))!=1)
        while (!iswspace(ch=getwchar())) if (ch==WEOF) return ;
    }
    top++;
    
    if (top <= bottom) {
      for (size_t i=top; i<=bottom; i++) {
        while ((code=wscanf(L"%d", *(A+i)+right))!=1) 
          while (!iswspace(ch=getwchar())) if (ch==WEOF) return ;
      }
      right--;
    }
    
    if (top <= bottom && left <= right) {
      for (size_t i=right; i>=left; i--) {
        while ((code=wscanf(L"%d", *(A+bottom)+i))!=1) 
          while (!iswspace(ch=getwchar())) if (ch==WEOF) return ;
        if (i==0) break;
      }
      bottom--;
    }

    if (left <= right && top <= bottom) {
      for (size_t i=bottom; i>=top; i--) {
        while ((code=wscanf(L"%d", *(A+i)+left))!=1) 
          while (!iswspace(ch=getwchar())) if (ch==WEOF) return ;
        if (i==0) break;
      }
      left++;
    }
  }
}

int main () {
  setlocale(LC_ALL, "");

  // task1
  wchar_t buffer[BUF_SIZE] = {0};
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
    while ((code=wscanf(L"%d", (A+i)))!=1) 
      while (!iswspace(ch=getwchar())) if (ch==WEOF) return -1;
  while (!iswspace(ch=getwchar()));
  wprintf(L"out: %d\n", sum_odd(A, N));

  // task3
  len=0;
  fputws(L"\nTask #3\nin: ", stdout);
  for (; len<BUF_SIZE && (ch=getwchar())!=WEOF && ch!=L'\n'; len++) 
    *(buffer+len)=ch;
  if (len<BUF_SIZE) len++;
  *(buffer+len) = L'\0';
  wprintf(L"out: %ls\n", rmwvowel(buffer, len));

  // task4
  len=0;
  fputws(L"\nTask #4\nin: ", stdout);
  for (; len<BUF_SIZE && (ch=getwchar())!=WEOF && ch!=L'\n'; len++) 
    *(buffer+len)=ch;
  if (len<BUF_SIZE) len++;
  *(buffer+len) = L'\0';
  wprintf(L"out: %lu\n", min_suffix(buffer, len));

  // task5
  len=0;
  fputws(L"\nTask #5\nin: ", stdout);
  for (; len<BUF_SIZE && (ch=getwchar())!=WEOF && ch!=L'\n'; len++) 
    *(buffer+len)=ch;
  if (len<BUF_SIZE) len++;
  *(buffer+len) = L'\0';
  wprintf(L"out: %lu\n", max_asc_seq(buffer, len));

  // task6 
  int B[M][M] = {{0}};
  fputws(L"\nTask #6\nin: ", stdout);
  arr_spiral(B, M, M);
  fputws(L"out:\n", stdout);
  for (size_t i=0; i<M; i++) {
    for (size_t j=0; j<M; j++) 
      wprintf(L"%2d ", *(*(B+i)+j));
    putwchar(L'\n');
  }

  return 0;
}
