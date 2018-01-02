#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  int year;
  int month;
  double  money = initial;

  for(int i = 0; i<working.months; i++){
    year = startAge/12;
    month = startAge % 12;
    printf("Age %3d month %2d you have $%.2lf\n", year, month, money);
    money  = money + (money * working.rate_of_return) + working.contribution;
    startAge  ++;
  }

  for(int i = 0; i<retired.months; i++){
    year = startAge/12;
    month = startAge % 12;
    printf("Age %3d month %2d you have $%.2lf\n", year, month, money);
    money  = money + (money * retired.rate_of_return) + retired.contribution;
    startAge  ++;
  }
}

int main(void){
  int age = 327; //months
  double savings = 21345;
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(age, savings, working, retired);

  return EXIT_SUCCESS;
}
