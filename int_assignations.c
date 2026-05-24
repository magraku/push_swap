/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_assignations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariagraciaramirezku <mariagraciaramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:40:10 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/24 23:08:03 by mariagracia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *ft_lstnew(int content)
{
    t_list    *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

int    ft_atoi(const char *nptr)
{
    int        i;
    long    sign;
    long    nb;

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
    return (nb * sign);
}

int    ft_verify_digit(char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        if (!(is_alpha(str[i])))
            return (0);
        i++;
    }
    return (1);
}

t_list    *int_assignation(t_list **numbers, char *str)
{
    int    n;

    n = ft_atoi(str);
    ft_lstadd_back(&numbers, ft_lstnew(n));
    return (numbers);
}