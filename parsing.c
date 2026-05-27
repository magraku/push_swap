/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:02 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/28 00:17:30 by gerramir         ###   ########.fr       */
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
	write(2, "Error\n", 6);
	return (0);
}

int	flag_assignation(char *s1, char *s2, int *bench, int *index)
{
	int	flag;

	flag = 0;
	if (valid_flag(s1) > 0)
	{
		if (valid_flag(s1) > 1)
		{
			flag = valid_flag(s1);
			*bench = 0;
			*index = 2;
		}
		else if (valid_flag(s1) == 1 && valid_flag(s2) == 0)
		{
			flag = 0;
			*bench = 1;
			*index = 2;
		}
		else if (valid_flag(s1) == 1 && valid_flag(s2) > 1)
		{
			flag = valid_flag(s2);
			*bench = 1;
			*index = 3;
		}
	}
	return (flag);
}

void	charto_int(char **num, t_list **numbers)
{
	int	j;

	j = 0;
	while (num[j])
	{
		if (!(verify_digit_repetition(num[j])))
		{
			write(2, "Error\n", 6);
			return ;
		}
		*numbers = int_assignation(*numbers, num[j++]);
	}
}

int	main(int ac, char **av)
{
	t_list	*numbers;
	char	**num;
	int		bench;
	int		flag;
	int		j;

	numbers = NULL;
	j = 1;
	bench = 0;
	flag = flag_assignation(av[1], av[2], &bench, &j);
	while (av[j])
	{
		if (!(verify_digit_repetition(av[j])))
			return (write(2, "Error\n", 6), 0);
		else if (ft_findc(av[j], ' ' ))
		{
			num = ft_split(av[j], ' ');
			charto_int(num, &numbers);
			j++;
		}
		else
			numbers = int_assignation(numbers, av[j++]);
	}
	push_swap(numbers, bench, flag);
	return (0);
}

t_data	init()



int	main(int ac, char **av)
{
	t_data	*data;
	t_list	*numbers;
	char	**num;
	int		bench;
	int		flag;
	int		j;

	data = init(data);
	j = 1;
	bench = 0;
	flag = flag_assignation(av[1], av[2], &bench, &j);
	while (av[j])
	{
		if (!(verify_digit_repetition(av[j])))
			return (write(2, "Error\n", 6), 0);
		else if (ft_findc(av[j], ' ' ))
		{
			num = ft_split(av[j], ' ');
			charto_int(num, &numbers);
			j++;
		}
		else
			numbers = int_assignation(numbers, av[j++]);
	}
	push_swap(numbers, bench, flag);
	return (0);
}
// aritmetica de punteros, modificando 
//variables que viven en una funcion, desde otra funcion.
// por que necesito inicializar mi t_list *numbers con 	NULL?