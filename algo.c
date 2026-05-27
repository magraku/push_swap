/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:41:52 by axweinma          #+#    #+#             */
/*   Updated: 2026/05/27 19:57:32 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///sa (swap a): Swap the first two elements at the top of stack a.
//Do nothing if there is only one or no elements.

void    sa(t_list *a)// on lui envoie ladresse de la a pour pouvoir modifier directement la stack
{
    int tmp1;
    if(!a || !a->next)
        return;
    tmp1 = a->content;
    a->content = a->next->content;
    a->next->content = tmp1;
}


/// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.

void    sb(t_list *b)// on lui envoie ladresse de la a pour pouvoir modifier directement la stack
{
    int tmp1;
    if(!b || !b->next)
        return;
    tmp1 = b->content;
    b->content = b->next->content;
    b->next->content = tmp1;
}

/// ss (): sa and sb at the same time.
void    ss(t_list *a, t_list *b)
{
    sa(a);
    sb(b);
}

/// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

void    pa(t_list *a, t_list *b)
{
    if(!b)
        return;
    b->content
    
}

/// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

/// ra (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.
/*Récapitulatif de ce que fait ton code
LigneRôleif(!a)stack vide → on ne fait rien
tmp = *a sauvegarde le premier nœud
*a = (*a)->next la nouvelle tête devient le deuxième nœud
while((*a)->next)parcourt jusqu'au dernier nœud
*a = (*a)->next avance dans la liste
(*a)->next = tmp branche le dernier vers l'ancien premier
tmp->next = NULLferme la liste*/
void    ra(t_list **a)
{
    t_list *tmp;        
    if(!a || !*a)
        return;
    tmp = *a;
    *a = (*a)->next;
    while((*a)->next)
        *a = (*a)->next;
    (*a)->next = tmp;
    tmp->next = NULL;
}
/*Comme on en a parlé — a = a->next à l'intérieur de la fonction ne modifie que la copie locale de a. La vraie tête de liste dans ton main ne change pas.
C'est le problème fondamental de ra comparé à sa — dans sa tu modifiait les contenus des nœuds, donc pas besoin de changer la tête. Ici tu changes qui est la tête.

Ce qu'il faut changer
Juste la signature de ta fonction et les endroits où tu utilises a :

t_list *a devient t_list **a
a devient *a partout où tu accèdes à la tête
a->next devient (*a)->next*/


/// rb (rotate b): Shift up all elements of stack b by one.
// The first element becomes the last one.

void    rb(t_list **b)
{
    t_list *tmp;        
    if(!b)
        return;
    tmp = *b;
    *b = (*b)->next;
    while((*b)->next)
        *b = (*b)->next;
    (*b)->next = tmp;
    tmp->next = NULL;
}

/// rr (): ra and rb at the same time.
void    rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}


/// rra (reverse rotate a): Shift down all elements of stack a by one.
/// The last element becomes the first one.
void rra(t_list **a)
{
    t_list *tmp1;
    t_list *tmp2;
    t_list *tmp3;
    if(!a)
        return;
    tmp1 = *a;
    tmp2 = *a;
    while(tmp1->next->next)
        tmp1 = tmp1->next; //avant dernier node
    tmp3 = tmp1->next; // dernier
    tmp3->next = tmp2; // le dernier passe premier
    tmp1->next = NULL;
    *a = tmp3;
}

void rra(t_list **a)// avec previous warningggg warninggg
{
    t_list *tmp1;
    t_list *tmp2;
    t_list *tmp3;
    if(!a)
        return;
    tmp1 = *a;
    tmp2 = *a;
    while(tmp1->next->next)
        tmp1 = tmp1->next; //avant dernier node
    tmp3 = tmp1->next; // dernier
    tmp3->next = tmp2; // le dernier passe premier
    tmp3->prev = NULL; // le nouveau premier pointe sur null en tant que previous
    tmp1->next = NULL; // le nouveau dernier pointe sur NULL en tant que next
}



/// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
void rrb(t_list **b)
{
    t_list *tmp1;
    t_list *tmp2;
    t_list *tmp3;
    if(!b)
        return;
    tmp1 = *b;
    tmp2 = *b;
    while(tmp1->next->next)
        tmp1 = tmp1->next; //bvbnt dernier node
    tmp3 = tmp1->next; // dernier
    tmp3->next = tmp2; // le dernier pbsse premier
    tmp1->next = NULL;
    *b = tmp3;
}

/// rrr (): rra and rrb at the same time
void    rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}