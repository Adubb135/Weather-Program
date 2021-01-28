#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
#define YEARS 5
int main(void) 
{
  int i;
  int j;
  float yearlyAverage;
  float monthlyAverage;
  float total;

  //Making an array with each months name
  char *monthNames[MONTHS] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  // Making an array with the years
  int years[YEARS] = {2010, 2011, 2012, 2013, 2014};

  // Making an array with the monthly averages in it
  float arrayMonths[MONTHS] = {0};

  // Making an array with the monthly averages in it
  float arrayYears[YEARS] = {0};

  // Making an array with hardcoded weather values for every month in 5 years
  float arrayWeather[YEARS][MONTHS] = { 
    {12.5, 36.5, 48.5, 12.5, 21.9, 11.3, 9.6, 6.3, 5.4, 2.5, 7.3, 6.6},
    {2.3, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 ,9.9 , 10.1, 11.5, 21.3 ,60.3},
    {2.3, 3.3, 4.4, 4.8, 6.6, 8.9, 20.4 ,9.9 , 10.1, 11.5, 21.3 ,60.3},
    {70.1, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 ,9.9 , 10.1, 11.5, 21.3 ,60.3},
    {2.3, 3.3, 100.6, 5.5, 6.6, 7.7, 8.8 ,9.9 , 10.1, 11.5, 21.3 ,60.3}
    };

  // Calculate total rainfall
  for(i = 0; i < 5; ++i)
  {
    for(j = 0; j < 12; ++j)
    {
      total += arrayWeather[i][j];
    }
  }

  // Calculate each year's total rainfall (inches)
  for(i = 0; i < 5; ++i)
  {
    for(j = 0; j < 12; ++j)
    {
      arrayYears[i] += arrayWeather[i][j];
    }
  }


  // Calculate the monthly rainfall averages
  for(j = 0; j < 12; ++j)
  {
    for(i = 0; i < 5; ++i)
    {
      arrayMonths[j] += arrayWeather[i][j];
    }
    
    arrayMonths[j] /= 5;
  }

  // Calculate the yearly rainfall average
  yearlyAverage = (arrayYears[0] + arrayYears[1] + arrayYears[2] + arrayYears[3] + arrayYears[4]) / 5;

  // Printing out the year, as well as the average for each year to the right of it
  printf("YEAR    RAINFALL (inches)\n");
  for(i = 0; i < 5; ++i)
  {
    printf("%d    %.1fl\n", years[i], arrayYears[i]);
  }

  // Printing out the yearly average
  printf("\nThe yearly average is %.1fl inches.\n", yearlyAverage);

  // Printing out the monthly averages
  printf("\nMONTHLY AVERAGES: \n");
  for(i = 0; i < 12; ++i)
  {
    printf(" %s  ", monthNames[i]);

  }

  // Newline character to seperate the months with it's respective data
  printf("\n");
  for(i = 0; i < 12; ++i)
  {
    printf("%.1fl  ", arrayMonths[i]);

  }
  return 0;
}
