/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:08:44 by axweinma          #+#    #+#             */
/*   Updated: 2026/06/13 20:01:49 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	position_max(t_list *b)
{
	t_list	*tmp;
	int		max_index;
	int		pos;
	int		i;

	tmp = b;
	max_index = 0;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	chunks_push(t_data *data)
{
	int	max;
	int	size;

	while (data->b)
	{
		size = ft_lstsize(data->b);
		max = position_max(data->b);
		if (max <= size / 2)
			rb(&data->b, 1, data);
		else
			rrb(&data->b, 1, data);
		if (position_max(data->b) == 0)
			pa(&data->a, &data->b, data);
	}
}

static void	push_chunk(t_data *data, int min, int max)
{
	int	n;

	n = ft_lstsize(data->a);
	while (n-- > 0)
	{
		if (data->a->index >= min && data->a->index <= max)
			pb(&data->b, &data->a, data);
		else
			ra(&data->a, 1, data);
	}
}

void	fonction_medium(t_data *data)
{
	int	c;
	int	n;
	int	chunk_size;
	int	num_chunks;

	assign_rank(data->a);
	n = ft_lstsize(data->a);
	chunk_size = ft_sqrt(n);
	num_chunks = (n + chunk_size - 1) / chunk_size;
	c = 0;
	while (c < num_chunks)
	{
		push_chunk(data, c * chunk_size, (c + 1) * chunk_size - 1);
		c++;
	}
	chunks_push(data);
}
