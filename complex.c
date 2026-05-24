/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 20:04:27 by csodini           #+#    #+#             */
/*   Updated: 2026/05/24 20:45:46 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_assign_indexes(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		current->index = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				current->index++;
			runner = runner->next;
		}
		current = current->next;
	}
}

static int	ft_get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static int	ft_get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = ft_get_max_index(stack);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	ft_sort_bit(t_stack **stack_a, t_stack **stack_b, int bit,
		t_bench *bench)
{
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		if (((*stack_a)->index >> bit) & 1)
			ft_ra(stack_a, bench);
		else
			ft_pb(stack_a, stack_b, bench);
		i++;
	}
	while (*stack_b)
		ft_pa(stack_a, stack_b, bench);
}

void	ft_complex(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	bit;
	int	max_bits;

	if (!stack_a || !*stack_a || ft_issorted(*stack_a))
		return ;
	ft_assign_indexes(*stack_a);
	max_bits = ft_get_max_bits(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		ft_sort_bit(stack_a, stack_b, bit, bench);
		bit++;
	}
}
