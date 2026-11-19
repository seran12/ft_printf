#include "ft_printf.h"

static int	ft_format(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_putbase(va_arg(*ap, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_putbase(va_arg(*ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putbase(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			count += ft_format(*format, &ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
