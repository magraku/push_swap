/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inititialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:34:25 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/28 18:23:14 by gerramir         ###   ########.fr       */
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
	data->count = 0;
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

