/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:03:21 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/01 16:42:25 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_node **node)
{
	t_node *temp;

	temp = ft_lastnode(*node);
	before_last(*node)->next = NULL;
	temp->next = *node;
	*node = temp;
}

void    rotate_reverse_both(t_node **node1, t_node **node2)
{
    rotate_reverse(node1);
    rotate_reverse(node2);
}

void	rotate(t_node **node)
{
	t_node *temp;

	if (!*node)
		exit(1);
	temp = (*node)->next;
	ft_lastnode(*node)->next = *node;
	(*node)->next = NULL;
	*node = temp;
}

void	rotate_both(t_node **node1, t_node **node2)
{
	rotate(node1);
	rotate(node2);
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

void    push(t_node **node1, t_node **node2)
{
	t_node *temp;

    if (!*node1)
		exit(1);
	temp = (*node1)->next;
	(*node1)->next = *node2;
	*node2 = *node1;
	*node1 = temp;
}

void	swap(t_node **node)
{
	t_node *temp;

    if (!*node)
		exit(1);
	temp = (*node)->next; //2 3 4 NULL
	(*node)->next = (*node)->next->next; //3 4 NULL
	temp->next = *node; //1 3 4 NULL
	*node = temp; //2 1 3 4 NULL
}

void	swap_both(t_node **node1, t_node **node2)
{
    swap(node1);
    swap(node2);
}
