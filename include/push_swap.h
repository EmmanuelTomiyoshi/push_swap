/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:36:54 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 16:03:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

//NUMERIC VALUES
# define MAX_INT +2147483647
# define MIN_INT -2147483648
# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct s_push_swap
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		argc;
	int		*argv;
	int		*int_value; //
	int		*copy_value;
	int		*map_index;
	int		bits_size;

	int		center_pivot;
	int		allow_print_ops;
	int		allow_print_stacks;
	int 	list_size;

}				t_push_swap;

//#DATA_HANDLING
//------------------------------------------------------------
//Free memory
void	free_memory(t_push_swap *ps);

//Init data
void	init_data(t_push_swap *ps, int argc, char *argv[]);
void	init_position_sizes(t_push_swap *ps, int argc);
void	init_dynamic_data(t_push_swap *ps);
void	init_parsed_argv(t_push_swap *ps, char *argv[]);
void	build_stack(t_push_swap *ps);
//------------------------------------------------------------


//#ERROR_HANDLING
//------------------------------------------------------------
//Check arguments
void	check_args(int argc, char *argv[]);
void	check_valid_number(char *argv[]);
void	check_insufficient_args(int argc);
void	check_duplicates(int argc, char *argv[]);
void	check_is_sorted(int argc, char *argv[]);

//error message
void	error_message(void);

//utils_error_handling
void	check_is_digit(char *str);
void	check_limits_int(char *str);
//------------------------------------------------------------


//#NODE_OPERATIONS
//------------------------------------------------------------
void	ft_clearnode(t_node *stack);
int		count_node_elements(t_node **node);
t_node	*ft_lastnode(t_node *lst);
t_node	*ft_newnode(int content, int index);
void	ft_nodeadd_back(t_node **lst, t_node *last_node);
t_node	*before_last(t_node *node);
void	ft_nodeadd_front(t_node **lst, t_node *new);
void	ft_nodelete(t_node *lst, void (*del)(int));
//------------------------------------------------------------


//#PRINT_STACKS
//------------------------------------------------------------
void	print_stacks(t_node *a, t_node *b, t_push_swap *ps);
void	print_index(t_node *a, t_node *b, t_push_swap *ps);
void	printArray(int array[], int size);
//------------------------------------------------------------


//#PUSH_OPERATIONS
//------------------------------------------------------------
//operations
void	rotate_reverse(t_push_swap *ps, t_node **node);
void	rotate(t_push_swap *ps, t_node **node);
void	push(t_push_swap *ps, t_node **node1, t_node **node2);
void	swap(t_push_swap *ps, t_node **node);

//run
void	run_push(t_push_swap *ps, char *operation);
void	run_swap(t_push_swap *ps, char *operation);
void	run_rotate(t_push_swap *ps, char *operation);
void	run_rotate_reverse(t_push_swap *ps, char *operation);
//------------------------------------------------------------


//#SORT_ALGORITHM
//bubble_sort
void	bubble_sort(int *argv, int size);

//check_is_sorted
int		is_sorted(t_node **node);


//STACK A
void	sort_two_a(t_push_swap *ps);
void	sort_three_a(t_push_swap *ps);
void	sort_four_a(t_push_swap *ps);
void	sort_five_a(t_push_swap *ps);
//STACK B
void	sort_two_b(t_push_swap *ps);
void	sort_three_b(t_push_swap *ps);
void	sort_four_b(t_push_swap *ps);
void	sort_five_b(t_push_swap *ps);

//radix
void	radix(t_push_swap *ps);
void	radix_get_bit_size(t_push_swap *ps);
void	radix_sort(t_push_swap *ps);


void	create_index(t_push_swap *ps);
void	normalize_values(t_push_swap *ps);
void	*ft_intmemcpy(void *dest, const void *src, size_t n);

//utils_sort_algorithm
int		check_highest_number(t_push_swap *ps);
int		check_lowest_number(t_push_swap *ps);

#endif