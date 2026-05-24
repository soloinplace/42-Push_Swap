/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:10:17 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/24 20:55:51 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((i < (n - 1)) && ptr1[i] && ptr2[i] && (ptr1[i] == ptr2[i]))
		i++;
	return (ptr1[i] - ptr2[i]);
}

float	ft_disorder(long *tab, int size)
{
	int	i;
	int	j;
	int	disord;
	int	pair;

	if (size <= 1)
		return (0);
	disord = 0;
	pair = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				disord++;
			pair++;
			j++;
		}
		i++;
	}
	return ((float)disord / pair);
}

int	ft_getflag(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (!ft_strncmp(argv[1], "--simple", 10))
		return (1);
	if (!ft_strncmp(argv[1], "--medium", 10))
		return (2);
	if (!ft_strncmp(argv[1], "--complex", 10))
		return (3);
	if (!ft_strncmp(argv[1], "--adaptive", 10))
		return (4);
	return (0);
}
