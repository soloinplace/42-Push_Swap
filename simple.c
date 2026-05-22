/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:44:07 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/19 17:44:13 by tsalland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

int		ft_issorted(t_stack *list)
{
	while (list->next != NULL)
		{
			if (list->value > list->next->value)
				return (0);
			list = list->next;
		}
	return (1);
}

void	ft_simple(t_stack **stack_a, t_bench *bench)
{
	int	i;
	int count;

	count = 0;
	while (ft_issorted(*stack_a) == 0)
	{
		i = 0;
		while (i < (ft_lstsize(*stack_a) - 1) - count)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
			{
				ft_sa(stack_a, bench);
			}
			ft_ra(stack_a, bench);
			i++;
		}
		count++;
		while (i > 0)
		{
			ft_rra(stack_a, bench);
			i--;
		}
	}
}
