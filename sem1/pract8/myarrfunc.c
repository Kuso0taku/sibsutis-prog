#include "myarrfunc.h"

// finds max element
int fnd_max(int *arrptr, size_t n) {
  int m=*arrptr;
  for (size_t i=0; i<n; i++) m = (m >= *(arrptr+i)) ? m : *(arrptr+i);
  return m;
} 

// finds last positive element
int fnd_lst_pstv(int *arrptr, size_t n) {
  int lst = -1;
  for (size_t i=0; i<n; i++) lst = (*(arrptr+i) <= 0) ? lst : *(arrptr+i);
  return lst;
}

// counts elements multiple of k
size_t cnt_mltpl_k(int *arrptr, size_t n, int k) {
  size_t cnt=0;
  for (size_t i=0; i<n; i++) if (*(arrptr+i)%k==0) cnt++;
  return cnt;
}

// counts elements greater than average value of the array
size_t cnt_avg_grt(int *arrptr, size_t n) {
  int sum=0;
  for (size_t i=0; i<n; i++) sum+=*(arrptr+i);
  int avg = sum/n;
  size_t cnt=0;
  for (size_t i=0; i<n; i++) if (*(arrptr+i)>avg) cnt++;
  return cnt;
}
