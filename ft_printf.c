/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:53:21 by tsalland          #+#    #+#             */
/*   Updated: 2026/04/30 19:30:40 by tsalland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_putdecimal(int n, int fd)
{
    if (n < 10)
        ft_putchar_fd('0', fd);
    ft_putnbrbas("0123456789", n, fd);
}

int	ft_findparam(const char *str, va_list ap, int i)
{
	if (str[i] == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 2));
	else if (str[i] == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 2));
	else if (str[i] == '%')
		return (ft_putchar_fd('%', 2));
	else if (str[i] == 'd')
		return (ft_putnbrbas("0123456789", (long)va_arg(ap, int), 2));
	else if (str[i] == 'i')
		return (ft_putnbrbas("0123456789", (long)va_arg(ap, int), 2));
	else if (str[i] == 'u')
		return (ft_putnbrbas("0123456789", va_arg(ap, unsigned int), 2));
	else if (str[i] == 'x')
		return (ft_putnbrbas("0123456789abcdef", va_arg(ap, unsigned int), 2));
	else if (str[i] == 'X')
		return (ft_putnbrbas("0123456789ABCDEF", va_arg(ap, unsigned int), 2));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(ap, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count += (ft_findparam((str) + 1, ap, i++));
		else
			count += (ft_putchar_fd(str[i], 2));
		i++;
	}
	va_end(ap);
	return (count);
}

/*  #include <limits.h>
int	main(void)
{
	char	test[] = "test";
	char	*testnull;
	int		count;

	printf("\n==== %% ====\n");
	printf("ft :\n");
	count = ft_printf("%%%%%%%%\n");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%%%%%%%%\n");
	printf("count = %d\n", count);

	printf("\n==== %%s %%c ====\n");
	printf("ft :\n");
	count = ft_printf("s = %s -%%%%%%-  c = %c\n", "salut", 'T');
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("s = %s -%%%%%%-  c = %c\n", "salut", 'T');
	printf("count = %d\n", count);

	printf("\n==== %%d %%i ====\n");
	printf("ft :\n");
	count = ft_printf("dec = %d et base 10 = %i\n", 123456, 78910);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("dec = %d et base 10 = %i\n", 123456, 78910);
	printf("count = %d\n", count);

	printf("\n==== %%d %%u ====\n");
	printf("ft :\n");
	count = ft_printf("dec = %d et unsigned = %u\n", -1, -1);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("dec = %d et unsigned = %u\n", -1, -1);
	printf("count = %d\n", count);

	printf("\n==== %%x %%X ====\n");
	printf("ft :\n");
	count = ft_printf("x = %x et X = %X\n", 587, 587);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("x = %x et X = %X\n", 587, 587);
	printf("count = %d\n", count);

	printf("\n==== %%p ====\n");
	printf("ft :\n");
	count = ft_printf("p = %p\n", &test);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("p = %p\n", &test);
	printf("count = %d\n", count);

	printf("\n==== UINT_MAX ====\n");
	printf("ft :\n");
	count = ft_printf("%u\n", 4294967295U);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%u\n", 4294967295U);
	printf("count = %d\n", count);

	printf("\n==== INT_MAX INT_MIN ====\n");
	printf("ft :\n");
	count = ft_printf("intmax = %d intmin = %d\n", INT_MAX, INT_MIN);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("intmax = %d intmin = %d\n", INT_MAX, INT_MIN);
	printf("count = %d\n", count);

	printf("\n==== NULL ====\n");
	testnull = NULL;
	printf("ft :\n");
	count = ft_printf("sNULL = %s pNULL = %p\n", testnull, testnull);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("sNULL = %s pNULL = %p\n", testnull, testnull);
	printf("count = %d\n", count);

	printf("\n==== BASIC ====\n");
	printf("ft :\n");
	count = ft_printf("hello world\n");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("hello world\n");
	printf("count = %d\n", count);

	printf("\n==== EMPTY STRING ====\n");
	printf("ft :\n");
	count = ft_printf("");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%s", "");
	printf("count = %d\n", count);

	printf("\n==== ONLY %% ====\n");
	printf("ft :\n");
	count = ft_printf("%%\n");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%%\n");
	printf("count = %d\n", count);

	printf("\n==== %%c EDGE CASES ====\n");
	printf("ft :\n");
	count = ft_printf("%c\n", 'A');
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%c\n", 'A');
	printf("count = %d\n", count);
	printf("ft : (null char)\n");
	count = ft_printf("%c\n", 0);
	printf("count = %d\n", count);
	printf("og : (null char)\n");
	count = printf("%c\n", 0);
	printf("count = %d\n", count);

	printf("\n==== %%s EDGE CASES ====\n");
	printf("ft :\n");
	count = ft_printf("%s\n", "");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%s\n", "");
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%s\n", "a");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%s\n", "a");
	printf("count = %d\n", count);
	testnull = NULL;
	printf("ft :\n");
	count = ft_printf("%s\n", testnull);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%s\n", testnull);
	printf("count = %d\n", count);

	printf("\n==== %%d EDGE CASES ====\n");
	printf("ft :\n");
	count = ft_printf("%d\n", 0);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%d\n", 0);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%d\n", 1);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%d\n", 1);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%d\n", -1);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%d\n", -1);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%d\n", INT_MAX);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%d\n", INT_MAX);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%d\n", INT_MIN);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%d\n", INT_MIN);
	printf("count = %d\n", count);

	printf("\n==== %%u EDGE CASES ====\n");
	printf("ft :\n");
	count = ft_printf("%u\n", 0);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%u\n", 0);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%u\n", (unsigned int)-1);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%u\n", (unsigned int)-1);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%u\n", UINT_MAX);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%u\n", UINT_MAX);
	printf("count = %d\n", count);

	printf("\n==== %%x %%X EDGE CASES ====\n");
	printf("ft :\n");
	count = ft_printf("%x\n", 0);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%x\n", 0);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%x\n", (unsigned int)-1);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%x\n", (unsigned int)-1);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%x\n", INT_MAX);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%x\n", INT_MAX);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%X\n", UINT_MAX);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%X\n", UINT_MAX);
	printf("count = %d\n", count);

	printf("\n==== %%p EDGE CASES ====\n");
	printf("ft :\n");
	count = ft_printf("%p\n", &test);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%p\n", &test);
	printf("count = %d\n", count);
	printf("ft :\n");
	count = ft_printf("%p\n", (void *)0);
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%p\n", (void *)0);
	printf("count = %d\n", count);

	printf("\n==== MANY %% ====\n");
	printf("ft :\n");
	count = ft_printf("%%%%%%%%%%%%%%%%\n");
	printf("count = %d\n", count);
	printf("og :\n");
	count = printf("%%%%%%%%%%%%%%%%\n");
	printf("count = %d\n", count);

	return (0);
} */
