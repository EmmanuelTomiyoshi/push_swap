/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_node_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:07:19 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/10 21:07:31 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node_elements(t_node **node)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *node;
	while (temp)
	{
		if (!temp->next)
			return (i + 1);
		temp = temp->next;
		i++;
	}
	return (0);
}
