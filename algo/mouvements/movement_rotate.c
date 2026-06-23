/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:25:45 by mariagracia       #+#    #+#             */
/*   Updated: 2026/06/13 20:17:43 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int print, t_data *data)
{
	t_list	*tmp;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (print)
	{
		if (data->bench == 0)
			write(1, "ra\n", 3);
		data->ops->ra++;
		data->ops->total++;
	}
}

void	rb(t_list **b, int print, t_data *data)
{
	t_list	*tmp;
	t_list	*lbst;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	lbst = *b;
	while (lbst->next)
		lbst = lbst->next;
	lbst->next = tmp;
	tmp->next = NULL;
	if (print)
	{
		if (data->bench == 0)
			write(1, "rb\n", 3);
		data->ops->rb++;
		data->ops->total++;
	}
}

void	rr(t_list **a, t_list **b, t_data *data)
{
	ra(a, 0, data);
	rb(b, 0, data);
	if (data->bench == 0)
		write(1, "rr\n", 3);
	data->ops->rr++;
	data->ops->total++;
}
