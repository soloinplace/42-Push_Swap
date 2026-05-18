/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsalland <tsalland@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:09:31 by tsalland          #+#    #+#             */
/*   Updated: 2026/05/13 15:09:37 by tsalland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

int					ft_isdigit(int c);
long				ft_longatoi(const char *nptr);
char				*ft_strdup(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_stringerror(int argc, char **argv);
int					ft_chechdouble(long *tab, int size);
long				*ft_creattab(int argc, char **argv);
t_stack				*ft_init(int argc, char **argv);
void				ft_printlst(t_stack *lst);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_createstack(long *tab, int size);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_newnode(int value);
void				ft_swap(t_stack **lst);
void				ft_sa(t_stack **a);
void				ft_sb(t_stack **b);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_rotate(t_stack **list);
void				ft_ra(t_stack **a);
void				ft_rb(t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rrotate(t_stack **list);
void				ft_rra(t_stack **a);
void				ft_rrb(t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);

#endif
