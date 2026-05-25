#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/////////////////////////// list_stack
typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

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