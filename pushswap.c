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
	stack = ft_createstack(tab, size);
	free(tab);
	return (stack);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_a = ft_init(argc, argv);
// 	stack_b = NULL;
// 	if (!stack_a)
// 		return (write(2, "Error\n", 6));


// 	///// test  //////
// 	ft_printlst(stack_a);
// 	ft_printlst(stack_b);


// 	ft_ra(&stack_a);
// 	ft_ra(&stack_a);

// 	printf("\na  =======->\n");
// 	ft_printlst(stack_a);
// 	printf("\nb  =======->\n");
// 	ft_printlst(stack_b);

// 	ft_pb(&stack_a, &stack_b);
// 	printf("\na  =======->\n");
// 	ft_printlst(stack_a);
// 	printf("\nb  =======->\n");
// 	ft_printlst(stack_b);

// 	return (0);
// }

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = ft_init(argc, argv);
    stack_b = NULL;
    if (!stack_a)
        return (write(2, "Error\n", 6));

    printf("--- init ---\n");
    ft_printlst(stack_a);

    printf("--- sa ---\n");
    ft_sa(&stack_a);
    ft_printlst(stack_a);

    printf("--- pb ---\n");
    ft_pb(&stack_a, &stack_b);
    printf("a: "); ft_printlst(stack_a);
    printf("b: "); ft_printlst(stack_b);

    printf("--- ra ---\n");
    ft_ra(&stack_a);
    ft_printlst(stack_a);

    printf("--- rra ---\n");
    ft_rra(&stack_a);
    ft_printlst(stack_a);

    printf("--- pa ---\n");
    ft_pa(&stack_a, &stack_b);
    printf("a: "); ft_printlst(stack_a);
    printf("b: "); ft_printlst(stack_b);

    return (0);
}
