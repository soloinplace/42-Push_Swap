/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:55 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/25 20:01:20 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_longatoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	ft_stringerror(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (-1);
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (-1);
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) != 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_chechdouble(long *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
			return (-1);
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

long	*ft_creattab(int argc, char **argv)
{
	long	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(long) * (argc - 1));
	if (!tab)
		return (NULL);
	while (i < (argc - 1))
	{
		if (ft_strlen(argv[i + 1]) > 11)
		{
			free(tab);
			return (NULL);
		}
		tab[i] = ft_longatoi(argv[i + 1]);
		i++;
	}
	return (tab);
}
