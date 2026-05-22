
#include "pushswap.h"

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	i;
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = '\0';
}

int		ft_totalops(t_bench *bench)
{
	int	total;
	total = 0;
	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb + bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb + bench->rrr;
	return (total);
}

void	ft_printbench(float disord, t_bench *bench, int flag)
{
	(void)flag;
	ft_printf("[bench] disorder: %d.", (int)(disord * 100));
	ft_putdecimal((int)(disord * 10000) % 100, 2);
	ft_putstr_fd("%\n",2);
	if (flag == 1)
		ft_printf("[bench] strategy: simple / O(n2)\n");
	if (flag == 2)
		ft_printf("[bench] strategy: medium / O(nSQRn)\n");
	if (flag == 3)
		ft_printf("[bench] strategy: complex / O(n log n)\n");
	if (flag == 4)
	{
		if (disord <= 0.2)
			ft_printf("[bench] Adaptive:  / O(n2)\n");
		else if (disord <= 0.5)
			ft_printf("[bench] Adaptive:  / O(nSQRn)\n");
		else
			ft_printf("[bench] Adaptive:  / O(n log n)\n");
	}
	ft_printf("[bench] total_ops: %d\n", ft_totalops(bench));
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}