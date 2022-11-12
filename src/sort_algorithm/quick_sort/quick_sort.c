/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:10:15 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/11 23:47:11 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_element_data(t_push_swap *ps)
{
	ps->nelem = ps->argc;
	get_center_pivot(ps);
	printf("pivot: %d\n", ps->center_pivot);
	free(ps->new_argv);
	ps->last_elem = ft_lastnode(ps->stack_a)->value;
}

void	divide_by_pivot(t_push_swap *ps)
{
	int i;
	
	i = 0;
	while (i < ps->nelem)
	{
		if (ps->stack_a->value <= ps->center_pivot)
			run_push(ps, "pb");
		else
			run_rotate(ps, "ra");
		i++;
	}
	if (!is_sorted(&ps->stack_a))
		run_swap(ps, "sa");
}

void	method_a(t_push_swap *ps)
{
	if (ps->nelem == 5)
		sort_five_a(ps);
	else if (ps->nelem == 4)
		sort_four_a(ps);
	else if (ps->nelem == 3)
		sort_three_a(ps);
	print_stacks(ps->stack_a, ps->stack_b, ps);
}

// void	method_b(t_push_swap *ps)
// {
// 	if (ps->nelem == 5)
// 		sort_five_b(ps);
// 	else if (ps->nelem == 4)
// 		sort_four_b(ps);
// 	else if (ps->nelem == 3)
// 		sort_three_b(ps);
// 	print_stacks(ps->stack_a, ps->stack_b, ps);
// }

void	choose_best_method(t_push_swap *ps)
{
	method_a(ps);
}

void	divide_to_conquer(t_push_swap *ps)
{
	int	last;
	int i;

	init_element_data(ps);
	while (ps->nelem > 5)
	{
		divide_by_pivot(ps);
		ps->nelem = count_node_elements(&ps->stack_a);
		get_center_pivot(ps);
		free(ps->new_argv);
		print_stacks(ps->stack_a, ps->stack_b, ps);
		printf("pivot: %d\n", ps->center_pivot);
	}
	choose_best_method(ps);
}

void	quick_sort(t_push_swap *ps)
{
	divide_to_conquer(ps);
}



//outros

// void	divide_to_conquer(t_push_swap *ps)
// {
// 	int	last;
// 	int i;

// 	ps->nelem = ps->argc;
// 	get_center_pivot(ps);
// 	printf("pivot: %d\n", ps->center_pivot);
// 	free(ps->new_argv);
// 	last = ft_lastnode(ps->stack_a)->value;
// 	while (ps->nelem > 2) // > 5, sort_five()
// 	{
// 		i = 0;
// 		while (i < ps->nelem)
// 		{
// 			if (ps->stack_a->value <= ps->center_pivot)
// 				run_push(ps, "pb");
// 			else
// 				run_rotate(ps, "ra");
// 			i++;
// 		}
// 		if (!is_sorted(&ps->stack_a))
// 			run_swap(ps, "sa");
// 		ps->nelem = count_node_elements(&ps->stack_a);
// 		get_center_pivot(ps);
// 		free(ps->new_argv); // //
// 		print_stacks(ps->stack_a, ps->stack_b, ps);
// 		printf("pivot: %d\n", ps->center_pivot);
// 	}
// }

	// int	top_stack_a;
	
	// while (ps->stack_b)
	// {
	// 	if (!ps->stack_b->next)
	// 	{
	// 		run_rotate(ps, "ra");
	// 		run_push(ps, "pa");
	// 		print_stacks(ps->stack_a, ps->stack_b, ps);
	// 		break ;
	// 	}
	// 	top_stack_a = ps->stack_a->value;
	// 	// printf("top_stack_a: %d | ", top_stack_a);
	// 	// printf("top_stack_b: %d\n", ps->stack_b->value);
	// 	if (top_stack_a > ps->stack_b->value)
	// 		run_push(ps, "pa");
	// 	else if (top_stack_a < ps->stack_b->value)
	// 	{
	// 		run_rotate(ps, "ra");
	// 		run_push(ps, "pb");
	// 	}
	// 	else
	// 		break ;
	// 	print_stacks(ps->stack_a, ps->stack_b, ps);
	// }

	// // while (!is_sorted(ps))
	// // {
	// // 	run_rotate_reverse(ps, "rra");
	// // }
	// print_stacks(ps->stack_a, ps->stack_b, ps);

	// //rotate the last two
	// if (!is_sorted(&ps->stack_a))
	// {
	// 	run_rotate(ps, "ra");
	// }
	// print_stacks(ps->stack_a, ps->stack_b, ps);