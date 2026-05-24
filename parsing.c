/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariagraciaramirezku <mariagraciaramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:02 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/24 23:17:50 by mariagracia      ###   ########.fr       */
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
	ft_putstr("error");
	return (0);
}

int	main(int ac, char **av)
{
	int		j;
	t_list	*numbers;

	j = 1;
	if (valid_flag(av[1]) == 1) // when --bench flag
	{
		if (valid_flag(av[2]) > 1 && valid_flag(av[2]) < 6) // --bench and strategy as flag
		{
			while (av[j + 2])
			{
				if (!(t_verify_digit(av[j + 2])))
					return (write(1, "error", 5), 0);
				numbers = int_assignation(numbers, av[j + 2]);
				j++;
			}
			push_swap(numbers, 1, valid_flag(av[2]));  // we pass 1 for bench, and flag# for flag
		}
		else
		{
			while (av[j + 1]) // only --bench flag
			{
				if (!(ft_verify_digit(av[j + 1])))
					return (write(1, "error", 5), 0);
				numbers = int_assignation(numbers, av[j + 2]);
				j++;
			}
			push_swap(numbers, 1, 0);  // we pass 1 for bench, and 0 for no flag
		}
	}
	else if (valid_flag(av[1]) > 1 && valid_flag(av[1]) < 6) // valid flag no bench	
	{
		while (av[j + 1])
		{
			if (!(t_verify_digit(av[j + 1])))
				return (write(1, "error", 5), 0);
			numbers = int_assignation(numbers, av[j + 1]);
			j++;
		}
		push_swap(numbers, 0, valid_flag(av[1])); // we pass 0 for no bench, and flag# for flag 
	}
	else if	(ft_verify_digit(av[j])) // when just valid numbers
	{
		while (av[j])
		{
			if (!(ft_verify_digit(av[j])))
				return (write(1, "error", 5), 0);
			numbers = int_assignation(numbers, av[j + 2]);
			j++;
		}
		push_swap(numbers, 0, 0);  // we pass 0 for no bench, and 0 for no flag
	}
	else // when error
		return (write(1, "error", 5), 0);
}