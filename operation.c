/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:08:13 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/13 15:08:15 by tsalland         ###   ########.fr       */
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

	if (!*list)
		return ;
	tmp = (*list);
	current = (*list);
	(*list) = (*list)->next;
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


void	ft_rrotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*current;

	if(!*list)
		return ;
	current = (*list);
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