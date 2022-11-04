/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:03:21 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/03 21:03:59 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    rotate_reverse_both(t_node **node1, t_node **node2)
{
    rotate_reverse(node1);
    rotate_reverse(node2);
}

void	rotate_both(t_node **node1, t_node **node2)
{
	rotate(node1);
	rotate(node2);
}

void	swap_both(t_node **node1, t_node **node2)
{
    swap(node1);
    swap(node2);
}
