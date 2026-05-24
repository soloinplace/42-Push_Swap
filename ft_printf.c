/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:53:21 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/24 23:00:26 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putdecimal(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0', fd);
	ft_putnbrbas("0123456789", n, fd);
}

static int	ft_findparam(const char *str, va_list ap, int i)
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
