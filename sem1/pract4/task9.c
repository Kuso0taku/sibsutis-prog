#include <stdio.h>

void Temperature(double temp) {
  const double CELCUS1 = 5.0/9.0;
  const double CELCUS2 = 32.0;
  const double KELVIN = 273.16;

  double celcus = CELCUS1 * (temp - CELCUS2);
  double kelvin = celcus + KELVIN;
  printf("Temperature in Celcus: %.2lf°C\n", celcus);
  printf("Temperature in Kelvin: %.2lfK\n", kelvin);
}

int main() {
  printf("Welcome to temperature converter! To exit enter a letter\n\n");
  double temp;
  int code;
  do {
    printf("Enter temperature in Fahrenheit: ");
    code = scanf("%lf", &temp);
    if (code) {Temperature(temp);}
  } while (code);
  printf("Thanks for using my program!\n");
  
  return 0;
}
