/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/09 18:08:20 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	quick_sort(t_push_swap *ps)
// {
	
// }

void	bubble_sort(t_push_swap *ps)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i <= ps->argc)
	{
		j = 1;
		while (j < ps->argc - i)
		{
			if (ps->argv[j] > ps->argv[j + 1])
			{
				temp = ps->argv[j];
				ps->argv[j] = ps->argv[j + 1];
				ps->argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	get_center_pivot(t_push_swap *ps)
{
	bubble_sort(ps);
	ps->center_pivot = ps->argv[(ps->argc + 1) / 2];
}


int	main(int argc, char *argv[])
{
	t_push_swap	ps;

	check_args(argc, argv);
	init_data(&ps, argc, argv);
	stack_building(&ps);
	sort_five(&ps);
	print_stacks(ps.stack_a, ps.stack_b);
	free_memory(&ps);
	return (0);
}
