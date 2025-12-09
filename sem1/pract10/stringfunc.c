#include "stringfunc.h"

// works like iswspace
_Bool wisspace(wchar_t wch) {
  return wch==L' ' || wch==L'\t' || wch==L'\n';
}

// compare two words 
_Bool cmp(char word1[], char word2[]) {
  for (size_t i=0; *(word1+i)!='\0' && *(word2+i)!='\0'; i++) {
    if (*(word1+i) != *(word2+i)) return 0;
  }
  return 1;
}

// counts how many every character
size_t cnt_chs(wchar_t text[BUFFER_SIZE]) {
  size_t cnt_a=0;
  wchar_t ch;
  size_t cnts[N_CHS] = {0};

  for (size_t i=0; *(text+i)!=L'\0' && i<BUFFER_SIZE; i++) {
    ch = *(text+i);
    cnt_a++;
    switch (ch) {
      case L'ё': (*(cnts+N_CHS-7))++; break;
      case L'Ё': (*(cnts+N_CHS-6))++; break;
      case L'\t': (*(cnts+N_CHS-5))++; break;
      case L'\n': (*(cnts+N_CHS-4))++; break;
      case L'‐': (*(cnts+N_CHS-3))++; break;
      case L'–': (*(cnts+N_CHS-2))++; break;
      case L'—': (*(cnts+N_CHS-1))++; break;
      default:
        if (ch>=L' ' && ch<=L'~') (*(cnts+ch-L' '))++;
        else if (ch>=L'А' && ch <=L'я') (*(cnts + N_ASCII + ch-L'А'))++;
        break;
    }
  }
  
  size_t cnt_out=0; // counts how many times out smth just for beauty
  // output
  for (size_t i=0; i<N_CHS; i++) {
    if (*(cnts+i) != 0) {
      if (i <= L'~' - L' ') ch = L' '+i;
      else if (i < N_CHS-7) ch = L'А'+ i - N_ASCII;
      else 
        switch (i) {
          case (N_CHS-7): ch=L'ё'; break;
          case (N_CHS-6): ch=L'Ё'; break;
          case (N_CHS-5): 
            ch=L'\t'; wprintf(L"'\\t': %lu\t", *(cnts+i)); break;
          case (N_CHS-4): 
            ch=L'\n'; wprintf(L"'\\n': %lu\t", *(cnts+i)); break;
          case (N_CHS-3): ch=L'‐'; break;
          case (N_CHS-2): ch=L'–'; break;
          case (N_CHS-1): ch=L'—'; break;
        }
      if (ch!=L'\t' && ch!=L'\n') wprintf(L"'%lc': %lu\t", (wint_t)ch, *(cnts+i));
      if ((++cnt_out) % 10 == 0) putwchar(L'\n');
    }
  }
  return cnt_a;
}

// inserts exclemation mark in the on of each line
void ins_exclm_mark(wchar_t text[BUFFER_SIZE]) {
  for (size_t i=0; *(text+i)!=L'\0' && i<BUFFER_SIZE; i++) {
    if (*(text+i) == L'\n') putwchar(L'!');
    putwchar(*(text+i));
  }
}

// finds and counts words with dashes
size_t cnt_dash_wrds(wchar_t text[BUFFER_SIZE]) {
  size_t cnt=0, s=0; // dash words counter, word start index
  _Bool fdash=0; // if dash was met INSIDE a word
  for (size_t i=1; *(text+i)!=L'\0' && i<BUFFER_SIZE; i++) {
    if (wisspace(*(text+i))) {
      if (fdash) {
        for (size_t j=s; j<i; j++) putwchar(*(text+j));
        putwchar(L'\t');
        cnt++; fdash=0;
      }
      s=i+1;
    }
    if (*(text+i) == L'-' && 
      !(wisspace(*(text+i-1))) && !(wisspace(*(text+i+1)))) fdash=1;
    if (cnt!=0 && cnt%5==0) putwchar(L'\n');
  }
  return cnt;
}

// inserts 'с' after vowel and repeats vowel
void ins_c_after_vwl(wchar_t text[BUFFER_SIZE]) {
  for (size_t i=0; *(text+i)!=L'\0' && i<BUFFER_SIZE; i++) {
    if (
      (*(text+i) == L'a' || *(text+i) == L'A' ||
      *(text+i) == L'e' || *(text+i) == L'E' ||
      *(text+i) == L'i' || *(text+i) == L'I' ||
      *(text+i) == L'o' || *(text+i) == L'O' ||
      *(text+i) == L'u' || *(text+i) == L'U') ||

      (*(text+i) == L'а' || *(text+i) == L'А' ||
      *(text+i) == L'о' || *(text+i) == L'О' ||
      *(text+i) == L'у' || *(text+i) == L'У' ||
      *(text+i) == L'э' || *(text+i) == L'Э' ||
      *(text+i) == L'ы' || *(text+i) == L'Ы' ||
      *(text+i) == L'я' || *(text+i) == L'Я' ||
      *(text+i) == L'ё' || *(text+i) == L'Ё' ||
      *(text+i) == L'ю' || *(text+i) == L'Ю' ||
      *(text+i) == L'и' || *(text+i) == L'И')
    )
    {putwchar(*(text+i)); putwchar(L'с');}
    putwchar(*(text+i));
  }
}
