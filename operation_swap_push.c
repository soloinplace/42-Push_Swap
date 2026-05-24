/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:52:49 by csodini           #+#    #+#             */
/*   Updated: 2026/05/24 21:57:16 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_stack **lst)
{
	int	tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next->value;
	(*lst)->next->value = (*lst)->value;
	(*lst)->value = tmp;
}

void	ft_sa(t_stack **a, t_bench *s_bench)
{
	ft_swap(a);
	write(1, "sa\n", 3);
	s_bench->sa++;
}

void	ft_sb(t_stack **b, t_bench *s_bench)
{
	ft_swap(b);
	write(1, "sb\n", 3);
	s_bench->sb++;
}

void	ft_ss(t_stack **a, t_stack **b, t_bench *s_bench)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
	s_bench->ss++;
}

void	ft_pb(t_stack **a, t_stack **b, t_bench *s_bench)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
	s_bench->pb++;
}
