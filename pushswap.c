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
		printf("valeur = %d et index = %d.\n", lst->value, lst->index);
		lst = lst->next;
	}
}

void	ft_complex(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}
void	ft_adaptive(t_stack **stack_a, t_stack **stack_b, int disord, int flag, t_bench *bench)
{
	if ((disord < 0.2 && (flag == 4 || flag == 0)) || flag == 1)
		ft_simple(stack_a, bench);
	else if ((disord < 0.5 && (flag == 4 || flag == 0)) || flag == 2)
		ft_medium(stack_a, stack_b, bench);
	// else if ((disord >= 0.5 && (flag == 4 || flag == 0)) || flag == 4)
	// 	ft_complex();

}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;
	t_bench	bench;
	float	disord;
	int		benchflag;

	benchflag = 0;
	if (argc >= 2 && ft_strncmp(argv[1], "--bench", 8) == 0)
	{
		argv++;
		argc--;
		benchflag = 1;
	}
	ft_bzero(&bench, sizeof(bench));
	flag = ft_getflag(argc, argv);
	if (flag == -1)
		return (write(2, "Error\n", 6));
	if (flag >= 1 && flag <= 4)
		stack_a = ft_init(argc - 1, argv + 1, &disord);
	else
		stack_a = ft_init(argc, argv, &disord);
	stack_b = NULL;
	if (!stack_a)
		return (write(2, "Error\n", 6));

	ft_adaptive(&stack_a, &stack_b, disord, flag, &bench);

	if (benchflag == 1)
		ft_printbench(disord, &bench, flag);
	return (0);
}
