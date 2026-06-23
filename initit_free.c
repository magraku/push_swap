/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initit_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:52:02 by gerramir          #+#    #+#             */
/*   Updated: 2026/06/13 20:15:21 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ops	*init_ops(void)
{
	t_ops	*operations;

	operations = malloc(sizeof(t_ops));
	if (!operations)
		return (NULL);
	operations->pa = 0;
	operations->pb = 0;
	operations->ra = 0;
	operations->rb = 0;
	operations->rr = 0;
	operations->rra = 0;
	operations->rrb = 0;
	operations->rrr = 0;
	operations->sa = 0;
	operations->sb = 0;
	operations->ss = 0;
	operations->total = 0;
	return (operations);
}

t_data	*init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = NULL;
	data->b = NULL;
	data->seen = NULL;
	data->ops = init_ops();
	if (!data->ops)
	{
		free(data);
		return (NULL);
	}
	data->bench = 0;
	data->strat = 0;
	data->error = 0;
	data->disorder = 0;
	return (data);
}

static void	free_lists(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		while (*lst && (*lst)->next)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
		free(*lst);
	}
}

void	ft_free(t_data *data)
{
	if (!data)
		return ;
	if (data->a)
		free_lists(&data->a);
	if (data->b)
		free_lists(&data->b);
	if (data->seen)
		free_lists(&data->seen);
	if (data->ops)
		free(data->ops);
	free(data);
}
