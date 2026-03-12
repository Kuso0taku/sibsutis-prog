#include <stdlib.h> // malloc, free
#include "bitrgbled_field.h"

// malloc new structure
rgbled *rgbled_field_create(void) {
  rgbled* rgb = (rgbled*)malloc(sizeof(rgbled));
  rgb->red = 0;
  rgb->green = 0;
  rgb->blue = 0;
  rgb->bright = 0;
  rgb->temp = 0;
  rgb->type = 0;
  rgb->mode = 0;
  return rgb;
}

// free memory
void rgbled_field_free(rgbled* rgb) {
  free(rgb);
}

// some functions to get a specific value from rgbled structure
unsigned char rgbled_field_get_red(rgbled* rgb) {
  return rgb->red;
}

unsigned char rgbled_field_get_green(rgbled* rgb) {
  return rgb->green;
}

unsigned char rgbled_field_get_blue(rgbled* rgb) {
  return rgb->blue;
}

unsigned char rgbled_field_get_bright(rgbled* rgb) {
  return rgb->bright;
}

unsigned int rgbled_field_get_temp(rgbled* rgb) {
  return rgb->temp;
}

unsigned char rgbled_field_get_type(rgbled* rgb) {
  return rgb->type;
}

unsigned char rgbled_field_get_mode(rgbled* rgb) {
  return rgb->mode;
}

// some functions to set a specific value from rgbled structure
void rgbled_field_set_red(rgbled* rgb, unsigned char red) {
  rgb->red = red;
}

void rgbled_field_set_green(rgbled* rgb, unsigned char green) {
  rgb->green = green;
}

void rgbled_field_set_blue(rgbled* rgb, unsigned char blue) {
  rgb->blue = blue;
}

void rgbled_field_set_bright(rgbled* rgb, unsigned char bright) {
  rgb->bright = bright;
}

void rgbled_field_set_temp(rgbled* rgb, unsigned int temp) {
  rgb->temp = temp;
}

void rgbled_field_set_type(rgbled* rgb, unsigned char type) {
  rgb->type = type;
}

void rgbled_field_set_mode(rgbled* rgb, unsigned char mode) {
  rgb->mode = mode;
}
