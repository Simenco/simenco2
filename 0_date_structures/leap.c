#include "main.h"

/**
 * leap - to check leap year
 * @year: parameter
 * 
 * Return: If true returns 1 else 0*/

int leap(int year)
{
  if (year % 4)
	  return (1);
  else
	  return (0);
}
