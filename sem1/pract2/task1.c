#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("Overflow: \n\n");

  // int overflow 
  short int s = SHRT_MAX;
  printf("short int overflow: s=%hd, s+1=%hd, s+2=%hd\n", s, s+1, s+2);
  
  unsigned short int u_s = USHRT_MAX;
  printf("unsigned short int overflow: u_s=%hu, u_s+1=%hu, u_s+2=%hu\n", 
         u_s, u_s+1, u_s+2);

  int i = INT_MAX;
  printf("\nint overflow: i=%d, i+1=%d, i+2=%d\n", i, i+1, i+2);
  unsigned int u_i = UINT_MAX;
  printf("unsigned int overflow: u_i=%u, u_i+1=%u, u_i+2=%u\n", 
         u_i, u_i+1, u_i+2);
  
  long int l = LONG_MAX;
  printf("\nlong int overflow: l=%ld, l+1=%ld, l+2=%ld\n", l, l+1, l+2);
  unsigned long int u_l = ULONG_MAX;
  printf("unsigned long int overflow: u_l=%lu, u_l+1=%lu, u_l+2=%lu\n", 
         u_l, u_l+1, u_l+2);
  
  long long int ll = LLONG_MAX;
  printf("\nlong long int overflow: ll=%lld, ll+1=%lld, ll+2=%lld\n",
         ll, ll+1, ll+2);
  unsigned long long int u_ll = ULLONG_MAX;
  printf("unsigned long long int overflow: u_ll=%llu, u_ll+1=%llu, u_ll+2=%llu\n", 
         u_ll, u_ll+1, u_ll+2);


  unsigned char ch = UCHAR_MAX;
  printf("\nunsignedchar overflow: ch=%c=%d, ch+1=%c=%d, ch+2=%c=%d\n", 
         ch, ch, (char)(ch+1), (char)(ch+1), (char)(ch+2), (char)(ch+2));
  signed char s_ch = SCHAR_MAX;
  printf("signed char overflow: ch=%c=%d, ch+1=%c=%d, ch+2=%c=%d\n", 
         s_ch, s_ch, (char)(s_ch+1), (char)(s_ch+1), 
         (char)(s_ch+2), (char)(s_ch+2));
  
  // float overflow
  float f = FLT_MAX;
  printf("\nfloat overflow: f=%e, f+f=%f\n", f, f+f);
  
  double d = DBL_MAX;
  printf("double overflow: d=%e, d+d=%lf\n", d, d+d);

  long double ld = LDBL_MAX;
  printf("double overflow: ld=%Le, ld+ld=%Lf\n", ld, ld+ld);


  printf("\n\nUnderflow:\n");

  // underflow testing
  float f_num = 1.0f;
  printf("float underflow: f_num=%e, f_num+1e-7f=%e\n", 
         f_num, f_num+1e-7f);
  
  double d_num = 1.0f;
  printf("double underflow: d_num=%e, d_num+1e-14f=%e\n", 
         d_num, d_num+1e-14f);

  long double ld_num = 1.0f;
  printf("long double underflow: ld_num=%Le, ld_num+1e-28f=%Le\n", 
         ld_num, ld_num+1e-28f);


  return 0;
}
