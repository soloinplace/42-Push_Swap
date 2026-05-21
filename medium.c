/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:27:48 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/21 15:27:51 by tsalland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int ft_sqrt(int n)
{
    int i;

    i = 1;
    while (i * i <= n)
        i++;
    return (i - 1);
}

void	ft_setindex(t_stack **list)
{
	t_stack *current;
	t_stack *save;

	current = (*list);
	while (current != NULL)
	{
		save = (*list);
		while (save != NULL)
		{
			if (save->value < current->value)
			{
				current->index++ ;
			}
		save = save->next;
		}
		current = current->next;
	}
}

int	ft_rangindex(t_stack *lst, int index)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		if (lst->index == index)
		{
			return (i);
		}
		i++;
		lst = lst->next;
	}
	return (i);
}
void	ft_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	count;
	int size;

	ft_setindex(stack_a);
	size = ft_lstsize((*stack_a));
	count = 0;
	chunk = ft_sqrt(ft_lstsize((*stack_a))) * 2;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index <= (chunk - 1) || size == count)
		{
			if (count == (chunk - 1)|| size == count)
				chunk = chunk + ft_sqrt(ft_lstsize((*stack_a))) * 2;
			ft_pb(stack_a, stack_b);
			count++;
		}
		else
			ft_ra(stack_a);
	}
	count--;
	while ((*stack_b) != NULL)
	{
		if ((*stack_b)->index == count)
		{
			ft_pa(stack_a, stack_b);
			count--;
		}
		else
		{
			if (ft_rangindex(*stack_b, count) < (ft_lstsize(*stack_b) / 2))
				ft_rb(stack_b);
			else
				ft_rrb(stack_b);
		}
	}
	//ft_printlst(*stack_a);
}
