/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:33:59 by gerramir          #+#    #+#             */
/*   Updated: 2026/06/13 19:45:22 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_data *data)
{
	t_list	*tmp;
	double	count;
	double	des;

	count = 0;
	des = 0;
	tmp = data->a;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			des++;
		tmp = tmp->next;
		count++;
	}
	if (count == 0)
		return (0);
	return (des / count);
}

void	fonction_adaptive(t_data *data)
{
	if (data->disorder == 0)
		return ;
	else if (data->disorder <= 0.2)
		fonction_simple(data);
	else if (data->disorder <= 0.5)
		fonction_medium(data);
	else
		fonction_complex(data);
}
