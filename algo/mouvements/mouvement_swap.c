/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:41:52 by axweinma          #+#    #+#             */
/*   Updated: 2026/06/13 20:10:36 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// sa (swap a): Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_list **a, int print, t_data *data)
{
	t_list	*first;
	t_list	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (print)
	{
		if (data->bench == 0)
			write(1, "sa\n", 3);
		data->ops->sa++;
		data->ops->total++;
	}
}

/// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_list **b, int print, t_data *data)
{
	t_list	*first;
	t_list	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (print)
	{
		if (data->bench == 0)
			write(1, "sb\n", 3);
		data->ops->sb++;
		data->ops->total++;
	}
}

/// ss (): sa and sb at the same time.
void	ss(t_list **a, t_list **b, t_data *data)
{
	sa(a, 0, data);
	sb(b, 0, data);
	if (data->bench == 0)
		write(1, "ss\n", 3);
	data->ops->ss++;
	data->ops->total++;
}
