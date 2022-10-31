/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:54:02 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/27 12:54:02 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeadd_front(t_node **lst, t_node *new)
{
	if (*lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	*lst = new;
}
