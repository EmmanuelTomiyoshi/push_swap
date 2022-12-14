/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:50:51 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/11 12:18:04 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **node)
{
	t_node		*temp;

	temp = *node;
	while (temp)
	{
		if (!temp->next)
			return (1);
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
