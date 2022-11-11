/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:04:04 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/10 23:15:52 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*traverse_node(t_node **node, size_t index)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *node;
	while (i < index)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
		i++;
	}
	return (temp);
}
//remover depois último return (temp)
