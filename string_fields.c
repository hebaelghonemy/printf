#include "main.h"
/**
 * get_percision - gets the percision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
 */
char *get_percision(char *p, params_t *params, va_list ap)
{
int d = 0;
if (*p != '.')
return (p);
p++;
if (*P == '*')
{
d = va_arg(ap, int);
p++;
}
else
{
while (_isdigit(*P))
d = d * 10 + (*P++ - '0');
}
params->percision = d;
return (p);
}
