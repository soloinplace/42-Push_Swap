/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:09:12 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/13 15:09:16 by tsalland         ###   ########.fr       */
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
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		ft_lstadd_back(&stack, ft_newnode(tab[i++]));
	}
	return (stack);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_printlst(t_stack *lst) // retirer pour le push car printf
{
	while (lst != NULL)
	{
		printf("%d\n", lst->value);
		lst = lst->next;
	}
}

t_stack	*ft_init(int argc, char **argv)
{
	long	*tab;
	t_stack	*stack;
	int		size;

	if (argc < 2 || ft_stringerror(argc, argv) == -1)
		return (NULL);
	size = argc - 1;
	tab = ft_creattab(argc, argv);
	if (ft_chechdouble(tab, size) == -1)
	{
		free(tab);
		return (NULL);
	}
	printf("\n dicord = %f\n", ft_disorder(tab, size));
	stack = ft_createstack(tab, size);
	free(tab);
	return (stack);
}

void	ft_complex(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}
void	ft_adaptive(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;

	flag = ft_getflag(argc, argv);
	if (flag == -1)
	{
		return (write(2, "Error\n", 6));
	}
	if (flag >= 1 && flag <= 4)
	{
		stack_a = ft_init(argc - 1, argv + 1);
	}
	else
	{
		stack_a = ft_init(argc, argv);
	}
	stack_b = NULL;
	if (!stack_a)
		return (write(2, "Error\n", 6));
	if (flag == 1)
		ft_simple(&stack_a);
	else if (flag == 2)
		ft_medium(&stack_a, &stack_b);
	else if (flag == 3)
		ft_complex(&stack_a, &stack_b);
	else
		ft_adaptive(&stack_a, &stack_b);
	ft_printlst(stack_a);
	return (0);
}
