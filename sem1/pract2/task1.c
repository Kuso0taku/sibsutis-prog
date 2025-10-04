#include <stdio.h>

int main() {
  int i = 2147483647;
  printf("int overflow: i=%d, i+1=%d, i+2=%d\n", i, i+1, i+2);
  //unsigned int u_i = i*2+1;
  //printf("unsigned int overflow: u_i=%u, u_i+1=%u, u_i+2=%u\n", 
  //       u_i, u_i+1, u_i+2);
  
  float f = 3.40282347e38f;
  printf("\nfloat overflow: f=%e, f+f=%f\n", f, f+f);
  //float n_f = -3.40282347e38f;
  //printf("negative float overflow: n_f=%e, n_f+n_f=%d\n", n_f, n_f+n_f);
  
  double d = 1.79769313486231571e308;
  printf("double overflow: d=%e, d+d=%f\n", d, d+d);
  //double n_d = -1.79769313486231571e308;
  //printf("negative double overflow: n_d=%e, n_d+n_d=%f\n", n_d, n_d+n_d);

  /*char ch = 255;
  printf("\nchar overflow: ch=%c=%d, ch+1=%c=%d, ch+2=%c=%d\n", 
         ch, ch, (char)(ch+1), (char)(ch+1), (char)(ch+2), (char)(ch+2));
  signed char s_ch = 127;
  printf("signed char overflow: ch=%c=%d, ch+1=%c=%d, ch+2=%c=%d\n", 
         s_ch, s_ch, (char)(s_ch+1), (char)(s_ch+1), 
         (char)(s_ch+2), (char)(s_ch+2));
 */

  float f_num = 1.0f;
  printf("\nfloat underflow: f_num=%f, f_num+0.0000001f=%f", 
         f_num, f_num+0.0000001f);
  return 0;
}
