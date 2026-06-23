/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:45:31 by gerramir          #+#    #+#             */
/*   Updated: 2026/06/13 19:59:38 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list *a)
{
	int		max;
	t_list	*tmp;
	int		bits;

	max = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while (max)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void	assign_rank(t_list *a)
{
	int		rank;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a;
	while (tmp1)
	{
		tmp2 = a;
		rank = 0;
		while (tmp2)
		{
			if (tmp2->num < tmp1->num)
				rank++;
			tmp2 = tmp2->next;
		}
		tmp1->index = rank;
		tmp1 = tmp1->next;
	}
}

void	fonction_complex(t_data *data)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (!data->a || !data->a->next)
		return ;
	assign_rank(data->a);
	max_bits = get_max_bits(data->a);
	i = -1;
	while (++i < max_bits)
	{
		size = ft_lstsize(data->a);
		j = -1;
		while (++j < size)
		{
			if (!(((data->a)->index >> i) & 1))
				pb(&data->b, &data->a, data);
			else
				ra(&data->a, 1, data);
		}
		while (data->b)
			pa(&data->a, &data->b, data);
	}
}
