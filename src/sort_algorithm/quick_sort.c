/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:10:15 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/10 23:19:55 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_center_pivot(t_push_swap *ps)
{
	int	*argv;

	argv = create_sub_array(ps);
	bubble_sort(argv, ps->nelem);
	ps->center_pivot = argv[(ps->nelem - 1) / 2];
}

int	*create_sub_array(t_push_swap *ps)
{
	t_node	*temp;
	int		i;

	i = 0;
	ps->new_argv = ft_calloc(ps->nelem, sizeof(int));
	temp = ps->stack_a;
	while (temp)
	{
		ps->new_argv[i] = temp->value;
		if (!temp->next)
			return (ps->new_argv);
		temp = temp->next;
		i++;
	}
}

void	divide_to_conquer(t_push_swap *ps)
{
	int	last;

	ps->nelem = ps->argc;
	get_center_pivot(ps);
	free(ps->new_argv);
	last = ft_lastnode(ps->stack_a)->value;
	while (ps->nelem > 2)
	{
		while (ps->stack_a)
		{
			if (ps->stack_a->value == last)
			{
				run_rotate(ps, "ra");
				break ;
			}
			if (ps->stack_a->value <= ps->center_pivot)
				run_push(ps, "pb");
			else
				run_rotate(ps, "ra");
		}
		ps->nelem = count_node_elements(&ps->stack_a);
		get_center_pivot(ps);
		free(ps->new_argv); // //
		print_stacks(ps->stack_a, ps->stack_b, ps);
		// printf("pivot: %d\n", ps->center_pivot);
	}
}

void	quick_sort(t_push_swap *ps)
{
	int	top_stack_a;

	divide_to_conquer(ps);
	while (ps->stack_b)
	{
		if (!ps->stack_b->next)
		{
			run_rotate(ps, "ra");
			run_push(ps, "pa");
			print_stacks(ps->stack_a, ps->stack_b, ps);
			break ;
		}
		top_stack_a = ps->stack_a->value;
		// printf("top_stack_a: %d | ", top_stack_a);
		// printf("top_stack_b: %d\n", ps->stack_b->value);
		if (top_stack_a > ps->stack_b->value)
			run_push(ps, "pa");
		else if (top_stack_a < ps->stack_b->value)
		{
			run_rotate(ps, "ra");
			run_push(ps, "pb");			
		}
		else
			break ;
		print_stacks(ps->stack_a, ps->stack_b, ps);
	}
	//mudar
	// while (!is_sorted(ps))
	// {
	// 	run_rotate_reverse(ps, "rra");
	// }
	print_stacks(ps->stack_a, ps->stack_b, ps);
}