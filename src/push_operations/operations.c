/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:02:37 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 16:39:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_node **node)
{
	t_node	*temp;

	temp = ft_lastnode(*node);
	before_last(*node)->next = NULL;
	temp->next = *node;
	*node = temp;
}

void	rotate(t_node **node)
{
	t_node	*temp;

	if (!*node)
		return ;
	temp = (*node)->next;
	ft_lastnode(*node)->next = *node;
	(*node)->next = NULL;
	*node = temp;
}

void	push(t_node **node1, t_node **node2)
{
	t_node	*temp;

	if (!*node1)
		return ;
	temp = (*node1)->next;
	(*node1)->next = *node2;
	*node2 = *node1;
	*node1 = temp;
}

void	swap(t_node **node)
{
	t_node	*temp;

	if (!*node)
		return ;
	temp = (*node)->next;
	(*node)->next = (*node)->next->next;
	temp->next = *node;
	*node = temp;
}
