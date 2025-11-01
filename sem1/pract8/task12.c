/* rain.c -- находит суммарные данные по годам, средние значения за год и средние значения за месяц по данным об осадках за несколько лет */
#include <stdio.h>
#define MONTHS 12 // количество месяцев в году
#define YEARS 5 // количество лет, для которых доступны данные

float Total(int years, int months, const float arr[years][months]) {
  const float *ptr = &arr[0][0];
  float subtot, total;
  int year, month;
  for (year = 0, total = 0; year < years; year++)
  { // для каждого года суммировать количество осадков за каждый месяц
    for (month = 0, subtot = 0; month < months; month++, ptr++)
      subtot += *ptr;
    printf("%5d %15.1lf\n", 2010 + year, subtot);
    total += subtot; // общая сумма для всех лет
  }
  return total;
}

float Subtot(int years, int months, const float arr[years][months]) {
  const float *ptr;
  float subtot;
  int year, month;
  for (month = 0; month < months; month++)
  { // для каждого месяца суммировать количество осадков на протяжении годов
    ptr=&arr[0][month];
    for (year = 0, subtot = 0; year < years; year++, ptr += months)
      subtot += *ptr;
    printf("%4.1lf ", subtot/years);
  }
  return subtot;
}

int main(void)
{
// инициализация данными об осадках за период с 2010 по 2014 гг.
  const float rain[YEARS][MONTHS] =
  {
    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
  };
  float total;
  printf("ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
  total = Total(YEARS, MONTHS, rain);
  printf ("\nСреднегодовое количество осадков составляет %.1lf дюймов. \n\n",
          total/YEARS);
  printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n") ;
  printf (" Янв Фев Мар Апр Май Июн Июл Авг Сен Окт") ;
  printf(" Ноя Дек\n");
  Subtot(YEARS, MONTHS, rain);
  printf("\n");
  return 0;
}
