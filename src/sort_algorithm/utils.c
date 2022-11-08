/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:50:51 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/07 22:51:08 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *temp)
{
	while (temp)
	{
		if (!temp->next)
			return (0);
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	sorted_check(t_push_swap *ps)
{
	t_node		*temp;
	int status;

	status = -5;
	temp = ps->stack_a;
	if ((status = is_sorted(temp)) == 0)
	{
		free_memory(ps);
		exit(0);
	}
	else
		return ;
}