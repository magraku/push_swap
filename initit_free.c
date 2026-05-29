/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initit_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:34:25 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/29 17:00:41 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*init_node(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static t_ops	*init_ops(void)
{
	t_ops	*operations;

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
	return (operations);
}

t_data	*init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = init_node();
	if (!data->a)
		return (NULL);
	data->b = init_node();
	if (!data->b)
		return (NULL);
	data->ops = init_ops();
	if (!data->ops)
		return (NULL);
	data->bench = 0;
	data->strat = 0;
	data->fd = 0;
	data->segment = 0;
	return (data);
}

void	ft_free(t_data *data)
{
	if (!data)
		return ;
	if (data->a)
		free(data->a);
	if (data->b)
		free(data->b);
	free(data);
}

