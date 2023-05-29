#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define NULL_STRING "(null)"

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - structurs of parameters
 * struct specifier - struct token
 * @unsign: flag if value is unsign
 *
 * @plus_flag: if plus flag specified
 * @space_flag: if space flag specified
 * @hashtag_flag: if hashtag flag specified
 * @zero_flag: on if flag specified
 * @minus_flag: if minus flag specified
 *
 * @width: if width field specified
 * @percision: if percision specified
 *
 * @h_modifier: if h modifier specified
 * @l_modifier: if l modifier specified
*/
typedef struct parameters
{
	unsigned int unsign       : 1;

	unsigned int plus_flag    : 1;
	unsigned int space_flag   : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag    : 1;
	unsigned int minus_flag   : 1;

	unsigned int width;
	unsigned int percision;

	unsigned int h_modifier   : 1;
	unsigned int l_modifier   : 1;
} params_t
/**
 * struct specifier - struct specifier
 *
 * @valid: the valid char
 *
 * @f: function
*/
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} specifier_t;

int _puts(char *str);
int _putchar(int c);


int _printf(const char *format, ...);

int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_rev(va_list ap, params_t *params);
int print_ rot13(va_list ap, params_t *params);

char *convert(long int num, int base, int flags, params);

int print_from_to(char *start, char *stop, char *except);

int(*get_specifier(char *s))(va_list ap, params_t *params);
int get print func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);

char *get_width(char *s, params_t *params, va_list ap);
char *get_percision(char *p, params_t *params, va_list ap);

void int_params(params_t *params, va_list ap);

int_isdigit(int, c);
int_strlen(char *s);

int print_number(char *str, params_t *params);
int print_number_right_shift(char *s, params_t *params, va_list ap);
int print_number_left_shift(char *s, params_t *params, va_list ap);





#endif
