#include "ft_printf.h"

int		print_var(const char *restrict str, int *i, va_list ap)
{
	if (str[*i] == '%')
		return (1);
	if (str[*i] >= '0' && str[*i] <= '9')
		;
	else if (str[*i])
		;
	else if (str[*i])
		;
	else if (str[*i])
		;
	else if (str[*i])
		;
	else if (str[*i])
		;
	else if (str[*i])
		;
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	int			len;
	int			i;
	va_list		ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			len += print_var(format, &i, ap);
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}