/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:18:55 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 16:26:04 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap *ps)
{
	if (!is_sorted(&ps->stack_a))
		run_swap(ps, "sa");
}

void	sort_three(t_push_swap *ps)
{
	int	index;

	index = check_highest_number(ps);
	if (!is_sorted(&ps->stack_a))
	{
		if (index == 0)
		{
			run_rotate(ps, "ra");
			sort_two(ps);
		}
		else if (index == 1)
		{
			run_rotate_reverse(ps, "rra");
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
	if (!is_sorted(&ps->stack_a))
	{
		if (index == 0)
		{
			run_push(ps, "pb");
			sort_three(ps);
			run_push(ps, "pa");
		}
		else if (index == 3)
		{
			run_rotate_reverse(ps, "rra");
			sort_four(ps);
		}
		else
		{
			run_rotate_reverse(ps, "rra");
			sort_four(ps);
		}
	}
}

void	sort_five(t_push_swap *ps)
{
	int	index;

	index = check_lowest_number(ps);
	if (!is_sorted(&ps->stack_a))
	{
		if (index == 0)
		{
			run_push(ps, "pb");
			sort_four(ps);
			run_push(ps, "pa");
		}
		else if (index == 1 || index == 2)
		{
			run_rotate(ps, "ra");
			sort_five(ps);
		}
		else
		{
			run_rotate_reverse(ps, "rra");
			sort_five(ps);
		}
	}
}
