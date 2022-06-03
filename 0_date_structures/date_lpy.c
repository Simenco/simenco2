#include <stdio.h>

/**
 * struct date - structure definition for date
 * @day: object1
 * @month: object2
 * @year: object3
 */
struct date
{
	int day;
	int month;
	int year;
};

/**
 * date_check - this check the date
 * @m: month
 * @yr: year
 * desc: this function returns the number of days after checking
 * for leap year.
 * Return: int value, no of days
 */
int date_check(struct date d)
{
	int days;
        const int ar_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (((d.year % 4) == 0) && (d.month == 2))
		days = 29;
	else
		days = ar_month[d.month - 1];
	return (days);
}
/**
 * main - entry to the main function
 *
 * Return: 0 on success
 */
int main(void)
{
	int days;
	struct date today, tomorrow;

	printf("Please enter today's date dd mm yyyy: \n");
	scanf("%d%d%d", &today.day, &today.month, &today.year);

	days = date_check(today);
	
	while (((today.day > 28) && (today.month == 2)) || (today.day > 31) || (today.month > 12))
	{
		printf("Date invalid!!!\n");
		printf("Please enter today's date dd mm yyyy: \n");
		scanf("%d%d%d", &today.day, &today.month, &today.year);
	}
	if (today.day != days)
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
	printf("Tomorrow's date is %i/%i/%i.\n", tomorrow.day, 
			tomorrow.month, tomorrow.year);
	return (0);
}

