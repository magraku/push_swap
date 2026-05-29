/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_assignations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:40:10 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/29 14:53:08 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		return (NULL);
	return (nb * sign);
}

int	verify_digit_repetition(char *str)
{
	static t_list	*seen;
	t_list			*tmp;
	int				n;
	int				i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	n = ft_atoi(str);
	tmp = seen;
	while (tmp)
	{
		if (tmp->num == n)
			return (0);
		tmp = tmp->next;
	}
	ft_lstadd_back(&seen, ft_lstnew(n));
	return (1);
}

void	*int_assignation(t_list **numbers, char *str)
{
	int	n;

	n = ft_atoi(str);
	ft_lstadd_back(numbers, ft_lstnew(n));
}
