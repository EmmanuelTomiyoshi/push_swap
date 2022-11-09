/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:23:34 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/08 23:00:07 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap *ps)
{
	if (!is_sorted(ps))
		swap(&ps->stack_a);
}

void	sort_three(t_push_swap *ps)
{
	int	index;

	index = check_highest_number(ps);
	if (!is_sorted(ps))
	{
		if (index == 0)
		{
			rotate(&ps->stack_a);
			sort_two(ps);
		}
		else if (index == 1)
		{
			rotate_reverse(&ps->stack_a);
			sort_two(ps);
		}
		else
		{
			sort_two(ps);
		}
	}
}

void	sort_four(t_push_swap *ps)
{
	int	index;

	index = check_lowest_number(ps);
	if (!is_sorted(ps))
	{
		if (index == 0)
		{
			push(&ps->stack_a, &ps->stack_b);
			sort_three(ps);
			push(&ps->stack_b, &ps->stack_a);
		}
		else if (index == 3)
		{
			rotate_reverse(&ps->stack_a);
			sort_four(ps);
		}
		else
		{
			rotate_reverse(&ps->stack_a);
			sort_four(ps);
		}
	}
}

void	sort_five(t_push_swap *ps)
{
	int	index;

	index = check_lowest_number(ps);
	if (!is_sorted(ps))
	{
		if (index == 0)
		{
			push(&ps->stack_a, &ps->stack_b);
			sort_four(ps);
			push(&ps->stack_b, &ps->stack_a);
		}
		else if (index == 1 || index == 2)
		{
			rotate(&ps->stack_a);
			sort_five(ps);
		}
		else
		{
			rotate_reverse(&ps->stack_a);
			sort_five(ps);
		}
	}
}
