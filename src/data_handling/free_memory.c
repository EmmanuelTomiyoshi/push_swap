/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:18:25 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 15:13:12 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(t_push_swap *ps)
{
	free(ps->argv);
	free(ps->copy_value);
	free(ps->map_index);
	ft_clearnode(ps->stack_a);
	ft_clearnode(ps->stack_b);
}
