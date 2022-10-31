/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:49:28 by etomiyos          #+#    #+#             */
/*   Updated: 2022/05/02 15:49:28 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clearnode(t_node *stack)
{
	t_node *temp;

	if (stack == NULL)
		return ;
    while (stack != NULL)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}
