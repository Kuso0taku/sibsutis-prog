#include <stdio.h>
#include <stdlib.h> // for srand()
#include <time.h> // for time()

#define COL 10 
#define ROW 10

int main() {
  srand(time(NULL));
  for (int i=0; i<COL; i++) {
    for (int j=0; j< ROW; j++) printf("%d ", rand()%1000);
    putchar('\n');
  }
}
