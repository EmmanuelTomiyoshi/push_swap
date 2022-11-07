/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:19:12 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/27 12:19:12 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeadd_back(t_node **lst, t_node *last_node)
{
	t_node	*node;

	if (*lst == NULL)
		*lst = last_node;
	else
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = last_node;
	}
}

t_node	*before_last(t_node *node)
{
	while (node)
	{
		if (!node->next->next)
			return (node);
		node = node->next;
	}
	return (NULL);
}
