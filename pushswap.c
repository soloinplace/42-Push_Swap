/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:09:12 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/24 22:35:20 by csodini          ###   ########.fr       */
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

void	ft_adaptive(t_stack **stack_a, t_stack **stack_b, float disord,
		int flag, t_bench *bench)
{
	if (flag == 1 || ((flag == 4 || flag == 0) && disord < 0.2))
		ft_simple(stack_a, bench);
	else if (flag == 2 || ((flag == 4 || flag == 0) && disord < 0.5))
		ft_medium(stack_a, stack_b, bench);
	else if (flag == 3 || ((flag == 4 || flag == 0) && disord >= 0.5))
		ft_complex(stack_a, stack_b, bench);
}

static int	ft_getbench(int *argc, char ***argv)
{
	if (*argc >= 2 && ft_strncmp((*argv)[1], "--bench", 8) == 0)
	{
		(*argv)++;
		(*argc)--;
		return (1);
	}
	return (0);
}

static t_stack	*ft_getstack(int argc, char **argv, int flag, float *disord)
{
	if (flag >= 1 && flag <= 4)
		return (ft_init(argc - 1, argv + 1, disord));
	return (ft_init(argc, argv, disord));
}

int	main(int argc, char **argv)
{
	t_stack	*stacks[2];
	int		flag;
	t_bench	bench;
	float	disord;
	int		benchflag;

	benchflag = ft_getbench(&argc, &argv);
	ft_bzero(&bench, sizeof(bench));
	flag = ft_getflag(argc, argv);
	if (flag == -1)
		return (write(2, "Error\n", 6));
	stacks[0] = ft_getstack(argc, argv, flag, &disord);
	stacks[1] = NULL;
	if (!stacks[0])
		return (write(2, "Error\n", 6));
	ft_adaptive(&stacks[0], &stacks[1], disord, flag, &bench);
	if (benchflag == 1)
		ft_printbench(disord, &bench, flag);
	return (0);
}
