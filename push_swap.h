#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/////////////////////////// list_stack
typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
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
	t_list			*numbers;
	t_ops			ops;
	int				bench;
	int				strat;
	int				fd;
	int				segment;
}					t_data;

//me toca declarar a 0 los int y malloc los que necesitan malloc
/////////////////////////// functions
t_list				push_swap(t_list *numbers, int bench, int flag);
int					valid_flag(char *av);
int					ft_verify_digit(char *str);
int					ft_isalpha(int c);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *nptr);
t_list				*int_assignation(t_list **numbers, char *str);
void				ft_putstr(char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
size_t				ft_strlen(char *str);
int					ft_findc(char *str, char c);

#endif