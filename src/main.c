/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/11 23:38:52 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	ps;
	t_node		*temp;

	check_args(argc, argv);
	init_data(&ps, argc, argv);
	stack_building(&ps);
	print_stacks(ps.stack_a, ps.stack_b, &ps);
	quick_sort(&ps);
	// print_stacks(ps.stack_a, ps.stack_b, &ps);
	// temp = traverse_node(&ps.stack_a, 0);
	// print_stacks(ps.stack_a, ps.stack_b);
	// get_center_pivot(&ps);
	// quick_sort(&ps, 0, ps.argc - 1);
	// partition(&ps, 0, ps.argc - 1);
	free_memory(&ps);
	return (0);
}