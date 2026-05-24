/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:53:50 by csodini           #+#    #+#             */
/*   Updated: 2026/05/24 21:57:08 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pa(t_stack **a, t_stack **b, t_bench *s_bench)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	s_bench->pa++;
}

void	ft_rotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	current = *list;
	*list = (*list)->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	ft_ra(t_stack **a, t_bench *s_bench)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
	s_bench->ra++;
}

void	ft_rb(t_stack **b, t_bench *s_bench)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
	s_bench->rb++;
}

void	ft_rr(t_stack **a, t_stack **b, t_bench *s_bench)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
	s_bench->rr++;
}
