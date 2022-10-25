/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:00:08 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/24 12:23:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct  s_node
{
	int		value;
	void	*next;
}               t_node;


void	swap_nodes(t_node **list, int first_num, int second_num)
{
	t_node *node_one;
	t_node *last_node_one;
	t_node *node_two;
	t_node *last_node_two;
	t_node *temp;

	node_one = *list;
	last_node_one = NULL;
	while (node_one)
	{
		if (node_one->value == first_num)
			break ;
		last_node_one = node_one;
		node_one = node_one->next;
	}
	node_two = *list;
	last_node_two = NULL;
	while (node_two)
	{
		if (node_two->value == second_num)
			break ;
		last_node_two = node_two;
		node_two = node_two->next;
	}
	if (node_one->value == first_num && node_two->value == second_num)
	{
		if (last_node_one)
			last_node_one->next = node_two;
		if (last_node_two)
			last_node_two->next = node_one;
		temp = node_one->next;
		node_one->next = node_two->next;
		node_two->next = temp;
	}
}

void    insert_first(t_node **list, int num)
{
	t_node *new_node = ft_calloc(sizeof(t_node), 1);
	if (new_node)
	{
		new_node->value = num;
		new_node->next = *list;
		*list = new_node;
	}
	else
		ft_printf("Couldn't create node!\n");
}

void	debug_list(t_node **list)
{
	t_node *node;
	
	node = *list;
	while (node)
	{
		// if (node->next == NULL)
		// 	break ;
		ft_printf("node->value = %d | node->next = %p\n", node->value, node->next);
		node = node->next;
	}
}
int main()
{
	int i;
	int arr[6] = {4, 3, 5, 2, 7, 1};
	t_node *node;

	node = NULL;
	i = 0;
	while (i < 6)
	{
		insert_first(&node, arr[i]);
		i++;
	}
	debug_list(&node);
	swap_nodes(&node, 3, 7);
	ft_printf("\nOK!\n");
	debug_list(&node);
	return (0);
}

//memória x perfomance
//time complexity

//