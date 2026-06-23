/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 19:28:41 by mariagracia       #+#    #+#             */
/*   Updated: 2026/06/13 20:16:56 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// rra (reverse rotate a): Shift down all elements of stack a by one.
/// The last element becomes the first one.
void	rra(t_list **a, int print, t_data *data)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp1 = *a;
	tmp2 = *a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp3 = tmp1->next;
	tmp3->next = tmp2;
	tmp1->next = NULL;
	*a = tmp3;
	if (print)
	{
		if (data->bench == 0)
			write(1, "rra\n", 4);
		data->ops->rra++;
		data->ops->total++;
	}
}

/// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
void	rrb(t_list **b, int print, t_data *data)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp1 = *b;
	tmp2 = *b;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp3 = tmp1->next;
	tmp3->next = tmp2;
	tmp1->next = NULL;
	*b = tmp3;
	if (print)
	{
		if (data->bench == 0)
			write(1, "rrb\n", 4);
		data->ops->rrb++;
		data->ops->total++;
	}
}

void	rrr(t_list **a, t_list **b, t_data *data)
{
	rra(a, 0, data);
	rrb(b, 0, data);
	if (data->bench == 0)
		write(1, "rrr\n", 4);
	data->ops->rrr++;
	data->ops->total++;
}
