/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:36:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/10 20:00:49 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT +2147483647
# define MIN_INT -2147483648
# define TRUE 1
# define FALSE 0
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_push_swap
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		argc;
	int		*argv;
	int		*new_argv;
	
	int		center_pivot;
	int		allow_print_ops;
	int		nelem;
}				t_push_swap;

//Check arguments
void	check_args(int argc, char *argv[]);
void	check_valid_number(char *argv[]);
void	check_insufficient_args(int argc);
void	check_duplicates(int argc, char *argv[]);
void	check_is_sorted(int argc, char *argv[]);

//Error message
void	error_message(void);

//Init data
void	init_data(t_push_swap *ps, int argc, char *argv[]);
void	argv_atoi(t_push_swap *ps, char *argv[]);
void	stack_building(t_push_swap *ps);
int		is_sorted(t_push_swap *ps);
void	check_is_sorted(int argc, char *argv[]);
int		check_highest_number(t_push_swap *ps);
int		check_lowest_number(t_push_swap *ps);
void	sort_five(t_push_swap *ps);
void	sort_four(t_push_swap *ps);
void	sort_three(t_push_swap *ps);
void	sort_two(t_push_swap *ps);

//Node operations
t_node	*ft_newnode(int content);
void	ft_nodeadd_back(t_node **lst, t_node *last_node);
void	ft_nodeadd_front(t_node **lst, t_node *new);
void	ft_clearnode(t_node *stack);
void	ft_nodel(t_node *lst, void (*del)(int));
t_node	*ft_lastnode(t_node *lst);
t_node	*before_last(t_node *node);
void	stack_building(t_push_swap *ps);

//Push operations
void	rotate_reverse(t_push_swap *ps, t_node **node);
void	rotate(t_push_swap *ps, t_node **node);
void	push(t_push_swap *ps, t_node **node1, t_node **node2);
void	swap(t_push_swap *ps, t_node **node);
void	run_push(t_push_swap *ps, char *operation);
void	run_swap(t_push_swap *ps, char *operation);
void	run_rotate(t_push_swap *ps, char *operation);
void	run_rotate_reverse(t_push_swap *ps, char *operation);
t_node	*before_last(t_node *node);

// void	check_is_digit(char *str);
void	check_is_digit(char *str);
void	check_limits_int(char *str);

//Print stacks
void	print_stacks(t_node *a, t_node *b);
void	print_array(t_push_swap *ps);

//Sort algorithm
void	bubble_sort(int *argv, int size);
int		count_stack_elements(t_node **node);
int		*create_sub_array(t_push_swap *ps);

//Free memory
void	free_memory(t_push_swap *ps);

#endif