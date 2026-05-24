/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csodini <csodini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:25:41 by csodini           #+#    #+#             */
/*   Updated: 2026/05/24 22:35:32 by csodini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putnbrbas(char *base, long n, int fd);
int					ft_putp(char *base, unsigned long n, int fd);
int					ft_printf(const char *format, ...);
void				ft_putdecimal(int n, int fd);

size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
long				ft_longatoi(const char *nptr);
char				*ft_strdup(const char *s);
void				ft_bzero(void *s, size_t n);

int					ft_stringerror(int argc, char **argv);
int					ft_chechdouble(long *tab, int size);
long				*ft_creattab(int argc, char **argv);
float				ft_disorder(long *tab, int size);
int					ft_getflag(int argc, char **argv);

t_stack				*ft_init(int argc, char **argv, float *disord);
t_stack				*ft_createstack(long *tab, int size);
t_stack				*ft_newnode(int value);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
int					ft_issorted(t_stack *list);

void				ft_swap(t_stack **lst);
void				ft_sa(t_stack **a, t_bench *s_bench);
void				ft_sb(t_stack **b, t_bench *s_bench);
void				ft_ss(t_stack **a, t_stack **b, t_bench *s_bench);
void				ft_pb(t_stack **a, t_stack **b, t_bench *s_bench);
void				ft_pa(t_stack **a, t_stack **b, t_bench *s_bench);

void				ft_rotate(t_stack **list);
void				ft_ra(t_stack **a, t_bench *s_bench);
void				ft_rb(t_stack **b, t_bench *s_bench);
void				ft_rr(t_stack **a, t_stack **b, t_bench *s_bench);

void				ft_rrotate(t_stack **list);
void				ft_rra(t_stack **a, t_bench *s_bench);
void				ft_rrb(t_stack **b, t_bench *s_bench);
void				ft_rrr(t_stack **a, t_stack **b, t_bench *s_bench);

void				ft_simple(t_stack **stack_a, t_bench *bench);
void				ft_medium(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				ft_complex(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				ft_adaptive(t_stack **stack_a, t_stack **stack_b,
						float disord, int flag, t_bench *bench);

int					ft_sqrt(int n);
void				ft_setindex(t_stack **list);
int					ft_rangindex(t_stack *lst, int index);

void				ft_printbench(float disord, t_bench *bench, int flag);
int					ft_totalops(t_bench *bench);

#endif
