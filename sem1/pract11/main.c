#include "structfunc.h"

int main() {
  struct Game Lib[N_STRUCTS]; // aka game library of N_STRUCTS games
  for (size_t i=0; i<N_STRUCTS; i++) {
    wprintf(L"\tEnter the %lu struct:\n", i+1);
    if (setter(Lib+i) == WEOF) return -1;
  }
  
  for (size_t i=0; i<N_STRUCTS; i++) {
    putwchar(L'\n');
    view(*(Lib+i));
  }

  return 0;
}
