/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/03 20:11:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap ps;

	check_args(argc, argv);
	init_data(&ps, argc, argv);
	stack_building(&ps);
	print_stacks(ps.stack_a, ps.stack_b);
	free_memory(&ps);
    return (0);
}