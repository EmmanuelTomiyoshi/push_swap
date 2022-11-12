/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:36:01 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 13:37:53 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_push_swap *ps)
{
    int	bits_size;
	
	bits_size = 0;
	ps->list_size = ps->argc;
	//get_bit_size
    printf("list_size: %d\n", ps->list_size);
	while (ps->list_size >> bits_size)
	{
		bits_size++;
	}
	//
	int	i;
	int	j;
	i = 0;
	while (i < bits_size)
	{
		j = 0;
		while (j < ps->list_size)
		{
            // print_stacks(ps->stack_a, ps->stack_b, ps);
			if ((ps->stack_a->index >> i) & 1)
				rotate(ps, &ps->stack_a);
			else
				push(ps, &ps->stack_a, &ps->stack_b);
			j++;
		}
		while (ps->stack_b)
		{
            // print_stacks(ps->stack_a, ps->stack_b, ps);
			push(ps, &ps->stack_b, &ps->stack_a);
		}
		i++;
	}
    // print_stacks(ps->stack_a, ps->stack_b, ps);
}