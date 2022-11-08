/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/07 22:54:35 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	bubble_sort(t_push_swap *ps)
// {
// 	int		i;
// 	t_node	*aux;
	
// 	i = 0;
// 	// aux = ps->stack_a;
// 	while (i < ps->argc)
// 	{
// 		if (ps->stack_a->value > ps->stack_a->next->value)
// 			swap(&ps->stack_a);
// 		ps->stack_a = (ps->stack_a)->next;
// 		i++;
// 	}
// }

// void	bubble_sort(t_push_swap *ps)
// {
// 	int		i;
// 	int		step;

// 	step = 0;
// 	while (step < ps->argc)
// 	{
// 		i = 0;
// 		while (i < ps->argc - step)
// 		{
// 			if (ps->stack_a->next == NULL)
// 				break ;
// 			if (ps->stack_a->value > ps->stack_a->next->value)
// 				swap(&ps->stack_a);
// 			// rotate(&ps->stack_a);
// 			i++;
// 		}
// 		step++;
// 	}
// }

//#PAREI AQUI (fazer o sort até 5 antes de ir pro bubble)
// void	sort_two(t_push_swap *ps)
// {
// 	if ()
// 	if (ps->)
// }

int	main(int argc, char *argv[])
{
	t_push_swap	ps;

	check_args(argc, argv);
	init_data(&ps, argc, argv);
	stack_building(&ps);
	sorted_check(&ps);
	print_stacks(ps.stack_a, ps.stack_b);
	free_memory(&ps);
	return (0);
}
