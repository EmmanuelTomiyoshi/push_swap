/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:19:12 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/11 23:29:48 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_b(t_push_swap *ps)
{
	if (!is_sorted(&ps->stack_b))
		run_swap(ps, "sb");
}

void	sort_three_b(t_push_swap *ps)
{
	int	index;

	index = check_highest_number(ps);
	if (!is_sorted(&ps->stack_b))
	{
		if (index == 0)
		{
			run_rotate(ps, "rb");
			sort_two_b(ps);
		}
		else if (index == 1)
		{
			run_rotate_reverse(ps, "rrb");
			sort_two_b(ps);
		}
		else
		{
			sort_two_b(ps);
		}
	}
}

void	sort_four_b(t_push_swap *ps)
{
	int	index;

	index = check_lowest_number(ps);
	if (!is_sorted(&ps->stack_b))
	{
		if (index == 0)
		{
			run_push(ps, "pa");
			sort_three_b(ps);
			run_push(ps, "pb");
		}
		else if (index == 3)
		{
			run_rotate_reverse(ps, "rrb");
			sort_four_b(ps);
		}
		else
		{
			run_rotate_reverse(ps, "rrb");
			sort_four_b(ps);
		}
	}
}

void	sort_five_b(t_push_swap *ps)
{
	int	index;

	index = check_lowest_number(ps);
	if (!is_sorted(&ps->stack_b))
	{
		if (index == 0)
		{
			run_push(ps, "pa");
			sort_four_b(ps);
			run_push(ps, "pb");
		}
		else if (index == 1 || index == 2)
		{
			run_rotate(ps, "rb");
			sort_five_b(ps);
		}
		else
		{
			run_rotate_reverse(ps, "rrb");
			sort_five_b(ps);
		}
	}
}
