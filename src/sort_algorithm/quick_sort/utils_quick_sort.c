/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:58:06 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/11 18:58:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_center_pivot(t_push_swap *ps)
{
	int	*argv;

	argv = create_sub_array(ps);
	bubble_sort(argv, ps->nelem);
	printf("nelem: %d\n", ps->nelem);
	ps->center_pivot = argv[(ps->nelem - 1) / 2];
	printf("pivot: %d\n", ps->center_pivot);
}

int	*create_sub_array(t_push_swap *ps)
{
	t_node	*temp;
	int		i;

	i = 0;
	ps->new_argv = ft_calloc(ps->nelem, sizeof(int));
	temp = ps->stack_a;
	while (temp)
	{
		ps->new_argv[i] = temp->value;
		if (!temp->next)
			return (ps->new_argv);
		temp = temp->next;
		i++;
	}
}
