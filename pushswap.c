/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:09:12 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/25 19:41:36 by csodini          ###   ########.fr       */
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

void	ft_adaptive(t_stack **stack_a, t_stack **stack_b, t_context *ctx)
{
	if (ctx->flag == 1 || ((ctx->flag == 4 || ctx->flag == 0)
			&& ctx->disord < 0.2))
		ft_simple(stack_a, &ctx->bench);
	else if (ctx->flag == 2 || ((ctx->flag == 4 || ctx->flag == 0)
			&& ctx->disord < 0.5))
		ft_medium(stack_a, stack_b, &ctx->bench);
	else if (ctx->flag == 3 || ((ctx->flag == 4 || ctx->flag == 0)
			&& ctx->disord >= 0.5))
		ft_complex(stack_a, stack_b, &ctx->bench);
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
	t_stack		*stacks[2];
	t_context	ctx;

	if (argc == 1)
		return (0);
	ctx.benchflag = ft_getbench(&argc, &argv);
	ft_bzero(&ctx.bench, sizeof(ctx.bench));
	ctx.flag = ft_getflag(argc, argv);
	if (ctx.flag == -1)
		return (write(2, "Error\n", 6));
	stacks[0] = ft_getstack(argc, argv, ctx.flag, &ctx.disord);
	stacks[1] = NULL;
	if (!stacks[0])
		return (write(2, "Error\n", 6));
	ft_adaptive(&stacks[0], &stacks[1], &ctx);
	if (ctx.benchflag == 1)
		ft_printbench(ctx.disord, &ctx.bench, ctx.flag);
	ft_free_stack(&stacks[0]);
	ft_free_stack(&stacks[1]);
	return (0);
}
