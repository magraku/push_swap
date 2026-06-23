/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:31:09 by mariagracia       #+#    #+#             */
/*   Updated: 2026/06/14 18:16:24 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_double(double dis)
{
	int	int_part;
	int	dec_part;

	dis = dis * 100;
	int_part = (int)dis;
	dec_part = (int)((dis - int_part) * 100);
	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	if (dec_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(dec_part, 2);
	write(2, "%", 1);
}

static void	write_op(char *name, int val)
{
	write(2, name, ft_strlen(name));
	ft_putnbr_fd(val, 2);
}

void	print(char *flag, t_data *data)
{
	write(2, "[bench] disorder:  ", 19);
	print_double(data->disorder);
	write(2, "\n[bench] strategy:  ", 20);
	write(2, flag, ft_strlen(flag));
	write(2, "\n[bench] total_ops:  ", 21);
	ft_putnbr_fd(data->ops->total, 2);
	write(2, "\n[bench] sa:  ", 14);
	ft_putnbr_fd(data->ops->sa, 2);
	write_op("  sb:  ", data->ops->sb);
	write_op("  ss:  ", data->ops->ss);
	write_op("  pa:  ", data->ops->pa);
	write_op("  pb:  ", data->ops->pb);
	write(2, "\n[bench] ra:  ", 14);
	ft_putnbr_fd(data->ops->ra, 2);
	write_op("  rb:  ", data->ops->rb);
	write_op("  rr:  ", data->ops->rr);
	write_op("  rra:  ", data->ops->rra);
	write_op("  rrb:  ", data->ops->rrb);
	write_op("  rrr:  ", data->ops->rrr);
	write(2, "\n", 1);
}

void	bench(t_data *data)
{
	if (!data->bench)
		return ;
	if (data->strat == 2)
		print("Simple / O(n²)", data);
	else if (data->strat == 3)
		print("Medium / O(n√n))", data);
	else if (data->strat == 4)
		print("Complex / O(n log n)", data);
	else
	{
		if (data->disorder > 0.5)
			print("Adaptive / O(n log n) ", data);
		else if (data->disorder > 0.2)
			print("Adaptive / O(n√n)", data);
		else if (data->disorder > 0)
			print("Adaptive / O(n²)", data);
	}
}
