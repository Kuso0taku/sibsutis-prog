#include <stdio.h>
#include "bitrgbled_field.h"

void print_field(rgbled_field* rgbled) {
  printf("size: %zu bits\n", sizeof(rgbled_field));
  printf("red = %u\n", rgbled->red);
  printf("green = %u\n", rgbled->green);
  printf("blue = %u\n", rgbled->blue);
  printf("bright = %u\n", rgbled->bright);
  printf("temp = %u\n", rgbled->temp);
  printf("type = %u\n", rgbled->type);
  printf("mode = %u\n", rgbled->mode);
}

int main() {
  rgbled_field* rgbled = rgbled_field_create();
  print_field(rgbled);
  putchar('\n');
  
  rgbled_field_set_temp(rgbled, 17000);
  printf("temp = %u\n", rgbled_field_get_temp(rgbled));
  putchar('\n');
  
  rgbled_field_set_mode(rgbled, 2);
  rgbled_field_set_red(rgbled, 255);
  rgbled_field_set_green(rgbled, 256);
  rgbled_field_set_blue(rgbled, 255);
  rgbled_field_set_bright(rgbled, 175);
  rgbled_field_set_type(rgbled, 4);
  rgbled_field_set_temp(rgbled, 10000);

  print_field(rgbled);

  return 0;
}
