/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:03:02 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/28 02:55:10 by gerramir         ###   ########.fr       */
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

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	t_list			*numbers; // pas besoin
	int				count;
	int				bench;
	int				strat;
	int				fd;
	int				segment;
}					t_data;

void	init_ints(t_list *num)
{
	num->num = 0;
}

t_data	init(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_list));
	if (!data->a)
		return (NULL);
	data->b = malloc(sizeof(t_list));
	if (!data->b)
		return (NULL);
	data->numbers = malloc(sizeof(t_list));
	if (!data->numbers)
		return (NULL);
	init_ints(data->a);
	return (data);
}

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
	if ()
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