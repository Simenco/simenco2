#include <stdio.h>

/**
 * struct date - defines a date structure
 * @day: object1
 * @month: object2
 * @year: object3
*/

int main(void)
{
  struct date
  {
    int day;
    int month;
    int year;
  };
  const int days_of_the_month[12] = {31, 28, 31, 30, 31, 30,                       31, 31, 30, 31, 30, 31};
  struct date today, tomorrow;

  printf("Enter today's date dd mm yyyy\n");
  scanf("%i%i%i", &today.day, &today.month, &today.year);

  while ((today.day > days_of_the_month[today.month - 1]) || 
    (today.month > 12))
  {
      printf("invalid date!!!\n");
      printf("Enter today's date dd mm yyyy\n");
      scanf("%i%i%i", &today.day, &today.month, &today.year);
  }
 
  if (today.day != days_of_the_month[today.month - 1])
  {
    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;
  }
  else if (today.month == 12)
  {
    tomorrow.day = 1;
    tomorrow.month = 1;
    tomorrow.year = today.year + 1;
  }
  else
  {
    tomorrow.day = 1;
    tomorrow.month = today.month + 1;
    tomorrow.year = today.year;
  }
  printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.day,
    tomorrow.month, tomorrow.year % 100);
  return (0);
  
}
