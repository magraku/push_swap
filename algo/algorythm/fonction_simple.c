/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:18:10 by gerramir          #+#    #+#             */
/*   Updated: 2026/06/14 18:03:23 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	if (!a)
		return (1);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_index(t_list *a)
{
	int		i;
	t_list	*tmp;

	if (!a)
		return ;
	tmp = a;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	position_min(t_list *a)
{
	int		value;
	int		nbr;
	t_list	*tmp;

	tmp = a;
	value = tmp->index;
	nbr = tmp->num;
	while (tmp)
	{
		if (nbr > tmp->num)
		{
			value = tmp->index;
			nbr = tmp->num;
		}
		tmp = tmp->next;
	}
	return (value);
}

//pour verifier
void	print_stack(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		ft_putnbr_fd(tmp->num, 1);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	fonction_simple(t_data *data)
{
	int	pos;
	int	size;

	while (ft_lstsize(data->a) > 1)
	{
		size = ft_lstsize(data->a);
		assign_index(data->a);
		pos = position_min(data->a);
		while (pos != 0)
		{
			if (pos <= size / 2)
				ra(&data->a, 1, data);
			else
				rra(&data->a, 1, data);
			assign_index(data->a);
			pos = position_min(data->a);
		}
		pb(&data->b, &data->a, data);
	}
	while (data->b)
		pa(&data->a, &data->b, data);
}
