/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:54:14 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/24 20:56:42 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	i = -1;
	while (s[++i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putp(char *base, unsigned long n, int fd)
{
	int				count;
	unsigned long	nb;
	unsigned int	lenbase;

	count = 0;
	lenbase = ft_strlen(base);
	nb = n;
	if (nb >= lenbase)
		count = count + ft_putnbrbas(base, nb / lenbase, fd);
	ft_putchar_fd(base[(nb % lenbase)], fd);
	count = count + 1;
	return (count);
}

int	ft_putnbrbas(char *base, long n, int fd)
{
	long long	nb;
	int			lenbase;
	int			count;

	count = 0;
	lenbase = ft_strlen(base);
	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_fd('-', 2);
		count++;
	}
	if (nb >= lenbase)
		count = count + ft_putnbrbas(base, nb / lenbase, fd);
	ft_putchar_fd(base[(nb % lenbase)], fd);
	count = count + 1;
	return (count);
}
