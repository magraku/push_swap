/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:54:11 by gerramir          #+#    #+#             */
/*   Updated: 2026/06/14 17:22:06 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/////////////////////////// list_stack
typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_ops;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	t_list			*seen;
	t_ops			*ops;
	int				bench;
	int				strat;
	int				error;
	double			disorder;
}					t_data;
//////////////////////////// struct initialization and free
t_data				*init(void);
void				ft_free(t_data *data);

/////////////////////////// parsing
void				bench(t_data *data);
void				push_swap(t_data *data);
double				disorder(t_data *data);

void				print_stack(t_list *a);
int					verify_digit_repetition(char *str, t_list **seen,
						t_data *data);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(char *s1, char *s2, int len);
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *nptr, t_data *data);
void				int_assignation(t_list **numbers, char *str, t_data *data);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
size_t				ft_strlen(char *str);
int					ft_findc(char *str, char c);
//////// algo
void				fonction_simple(t_data *data);
void				fonction_medium(t_data *data);
void				fonction_complex(t_data *data);
void				fonction_adaptive(t_data *data);
int					valid_sort(t_list **a);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				assign_rank(t_list *a);
/////// mouvements
void				sa(t_list **a, int print, t_data *data);
void				sb(t_list **b, int print, t_data *data);
void				ss(t_list **a, t_list **b, t_data *data);

void				pa(t_list **a, t_list **b, t_data *data);
void				pb(t_list **b, t_list **a, t_data *data);

void				ra(t_list **a, int print, t_data *data);
void				rb(t_list **b, int print, t_data *data);
void				rr(t_list **a, t_list **b, t_data *data);

void				rra(t_list **a, int print, t_data *data);
void				rrb(t_list **b, int print, t_data *data);
void				rrr(t_list **a, t_list **b, t_data *data);

#endif