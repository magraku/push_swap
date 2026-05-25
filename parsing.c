/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:02 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/25 14:24:06 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_flag(char *av)
{
	if (ft_strcmp(av, "--bench") == 0)
		return (1);
	else if (ft_strcmp(av, "--simple") == 0)
		return (2);
	else if (ft_strcmp(av, "--medium") == 0)
		return (3);
	else if (ft_strcmp(av, "--complex") == 0)
		return (4);
	else if (ft_strcmp(av, "--adaptative") == 0)
		return (5);
	ft_putstr("Error");
	return (0);
}

int main(int ac, char **av)
{
	t_list *numbers;
	int bench;
	int flag;
	int j;

	j = 1;
	bench = 0;
	flag = 0;
	if (valid_flag(av[1]) > 0)
	{
		if (valid_flag(av[1]) > 1)
		{
			flag = valid_flag(av[1]);
			j = 2;
		}
		else if (valid_flag(av[1]) == 1 && valid_flag(av[2]) == 0)
		{
			bench = 1;
			j = 2;
		}
		else if (valid_flag(av[1]) == 1 && valid_flag(av[2]) > 1)
		{
			bench = 1;
			flag = valid_flag(av[2]);
			j = 3;
		}
	}

	while (av[j])
	{
		if (!(verify_digit_repetition(av[j])))
			return (write(1, "Error\n", 6), 0);
		numbers = int_assignation(numbers, av[j++]);
		else if (ft_findc(av[j], ' ' ))
		{
			ft_split(av[j]);
			
		}
	}
	push_swap(numbers, bench, flag);
	return (0);
}
