/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:36:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/31 15:37:44 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct		s_node
{
    int				value;
    struct s_node	*next;
}               	t_node;

typedef struct  s_push_swap
{
    t_node	*stack_a;
	t_node	*stack_b;
    
    int     argc;
}               t_push_swap;


void	check_args(int argc);
void	init_data(t_push_swap *ps, int argc);
t_node	*ft_newnode(int content);
void	ft_nodeadd_back(t_node **lst, t_node *last_node);
void	ft_nodeadd_front(t_node **lst, t_node *new);
void	ft_clearnode(t_node *stack);
void	ft_nodel(t_node *lst, void (*del)(int));
t_node	*ft_lastnode(t_node *lst);
t_node	*before_last(t_node *node);
void    print_stacks(t_node *a, t_node *b);

void	rotate_reverse(t_node **node);
void    rotate_reverse_both(t_node **node1, t_node **node2);
void	rotate(t_node **node);
void	rotate_both(t_node **node1, t_node **node2);
void    push(t_node **node1, t_node **node2);
void	swap(t_node **node);
void	swap_both(t_node **node1, t_node **node2);

#endif