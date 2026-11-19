#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

int	ft_putbase(unsigned long n, char *base)
{
	unsigned long	len;
	int				count;

	len = 0;
	while (base[len])
		len++;
	count = 0;
	if (n >= len)
		count += ft_putbase(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}

int	ft_putnbr(int n)
{
	long	l;
	int		count;

	l = n;
	count = 0;
	if (l < 0)
	{
		count += ft_putchar('-');
		l = -l;
	}
	return (count + ft_putbase(l, "0123456789"));
}

int	ft_putptr(void *p)
{
	int	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_putbase((unsigned long)p, "0123456789abcdef");
	return (count);
}
