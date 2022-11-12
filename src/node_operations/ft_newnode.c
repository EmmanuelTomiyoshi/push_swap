/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:19:21 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/27 12:19:21 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int content, int index)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = content;
	node->index = index;
	node->next = NULL;
	return (node);
}
