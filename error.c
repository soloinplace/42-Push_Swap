/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:55 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/13 15:08:04 by tsalland         ###   ########.fr       */
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
	int(i) = 0;
	long(mult) = 1;
	long(nb) = 0;
	int(neg) = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	i--;
	while (i >= 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb + ((nptr[i] - '0') * mult);
		mult = mult * 10;
		i--;
	}
	return (nb * neg);
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
		while (argv[i][j] != '\0')
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) != 1)
			{
				return (-1);
			}
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
	while (i < (argc - 1))
	{
		tab[i] = ft_longatoi(argv[i + 1]);
		i++;
	}
	return (tab);
}
