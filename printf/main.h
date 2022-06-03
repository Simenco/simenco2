#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_num(int num);
void _puts(char *str);
int hex(int num);
int _printf_S(char *s);
int print_rev(char *s);
int _rot13(char *s);
int _ptr(unsigned long int dec);
void base_convert(int num, int base);

#endif
