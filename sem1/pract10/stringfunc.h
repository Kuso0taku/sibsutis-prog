#include <wchar.h>

#define BUFFER_SIZE 10000 // max input buffer size

#define N_ASCII (L'~' - L' ' + 1) // ascii characters
#define N_RU (L'я' - L'А' + 3) // russian characters + 'ё' + 'Ё'
#define N_SPEC 5 // special characters ('\t', '\n', L'‐', L'–', L'—')
#define N_CHS (N_ASCII + N_RU + N_SPEC)

_Bool wisspace(wchar_t wch); // works like iswspace
_Bool cmp(char word1[], char word2[]); // compare two words
size_t cnt_chs(wchar_t text[BUFFER_SIZE]); // counts how many every character
void ins_exclm_mark(wchar_t text[BUFFER_SIZE]); // inserts exclemation mark in the end of lines
size_t cnt_dash_wrds(wchar_t text[BUFFER_SIZE]); // finds and counts words with dashes
void ins_c_after_vwl(wchar_t text[BUFFER_SIZE]); // inserts 'с' after vowel and repeats vowel
