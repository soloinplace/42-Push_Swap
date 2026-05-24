/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:54:22 by csodini           #+#    #+#             */
/*   Updated: 2026/05/24 21:57:13 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rrotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!*list || !(*list)->next)
		return ;
	current = *list;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = *list;
	*list = tmp;
}

void	ft_rra(t_stack **a, t_bench *s_bench)
{
	ft_rrotate(a);
	write(1, "rra\n", 4);
	s_bench->rra++;
}

void	ft_rrb(t_stack **b, t_bench *s_bench)
{
	ft_rrotate(b);
	write(1, "rrb\n", 4);
	s_bench->rrb++;
}

void	ft_rrr(t_stack **a, t_stack **b, t_bench *s_bench)
{
	ft_rrotate(a);
	ft_rrotate(b);
	write(1, "rrr\n", 4);
	s_bench->rrr++;
}
