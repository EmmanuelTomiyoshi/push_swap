/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:36:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/01 17:19:37 by etomiyos         ###   ########.fr       */
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
    int    *argv;
}               t_push_swap;


void	check_args(int argc, char *argv[]);
void	init_argv_data(t_push_swap *ps, char *argv[]);
void	init_data(t_push_swap *ps, int argc, char *argv[]);
t_node	*ft_newnode(int content);
void	ft_nodeadd_back(t_node **lst, t_node *last_node);
void	ft_nodeadd_front(t_node **lst, t_node *new);
void	ft_clearnode(t_node *stack);
void	ft_nodel(t_node *lst, void (*del)(int));
t_node	*ft_lastnode(t_node *lst);
t_node	*before_last(t_node *node);
void    print_stacks(t_node *a, t_node *b);
void	stack_building(t_push_swap *ps);

void	rotate_reverse(t_node **node);
void    rotate_reverse_both(t_node **node1, t_node **node2);
void	rotate(t_node **node);
void	rotate_both(t_node **node1, t_node **node2);
void    push(t_node **node1, t_node **node2);
void	swap(t_node **node);
void	swap_both(t_node **node1, t_node **node2);

void	argv_atoi(t_push_swap *ps, char *argv[]);

void	free_memory(t_push_swap *ps);
//	Error handling {
void	check_args(int argc, char *argv[]);
void	insufficient_args(int argc);
int		check_invalid_char(char *argv[]);
int		check_is_digit(char *str);
//	}

#endif