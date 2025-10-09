#include <stdio.h>
int main() {
  float speed;
  printf("Enter your download speed in mbit/s: ");
  scanf("%f", &speed);

  float file;
  printf("Enter size of your file in mb: ");
  scanf("%f", &file);

  float time = file*8/speed;
  printf("At a download speed of %.2f megabit per second, \n\
a %.2f megabyte file is downloaded in %.2f seconds\n", speed, file, time);

  return 0;
}
