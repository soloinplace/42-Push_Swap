/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:21:35 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/25 00:21:58 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return ;
}

t_stack	*ft_createstack(long *tab, int size)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		new = ft_newnode(tab[i]);
		if (!new)
		{
			ft_free_stack(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

t_stack	*ft_init(int argc, char **argv, float *disord)
{
	long	*tab;
	t_stack	*stack;
	int		size;

	if (argc < 2 || ft_stringerror(argc, argv) == -1)
		return (NULL);
	size = argc - 1;
	tab = ft_creattab(argc, argv);
	if (!tab)
		return (NULL);
	if (ft_chechdouble(tab, size) == -1)
	{
		free(tab);
		return (NULL);
	}
	stack = ft_createstack(tab, size);
	*disord = ft_disorder(tab, size);
	free(tab);
	return (stack);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
