/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:09:31 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/08 22:09:48 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_highest_number(t_push_swap *ps)
{
	t_node	*stack;
	int		highest_number;
	int		index;
	int		keep_index;

	highest_number = MIN_INT;
	index = 0;
	stack = ps->stack_a;
	while (stack)
	{
		if (stack->value > highest_number)
		{
			highest_number = stack->value;
			keep_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (keep_index);
}

int	check_lowest_number(t_push_swap *ps)
{
	t_node	*stack;
	int		highest_number;
	int		index;
	int		keep_index;

	highest_number = MAX_INT;
	index = 0;
	stack = ps->stack_a;
	while (stack)
	{
		if (stack->value < highest_number)
		{
			highest_number = stack->value;
			keep_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (keep_index);
}
