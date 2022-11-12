/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:36:01 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 15:56:51 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_push_swap *ps)
{
	radix_get_bit_size(ps);
	radix_sort(ps);
}

void	radix_get_bit_size(t_push_swap *ps)
{
	ps->bits_size = 0;
	ps->list_size = ps->argc;
	while (ps->list_size >> ps->bits_size)
	{
		ps->bits_size++;
	}
}

void	radix_sort(t_push_swap *ps)
{
	int	i;
	int	j;
	i = 0;
	while (i < ps->bits_size)
	{
		j = 0;
		while (j < ps->list_size)
		{
			if ((ps->stack_a->index >> i) & 1)
				run_rotate(ps, "ra");
			else
				run_push(ps, "pb");
			j++;
		}
		while (ps->stack_b)
		{
			run_push(ps, "pa");
		}
		i++;
	}
}
