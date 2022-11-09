/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:34:49 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/09 12:29:52 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node *a, t_node *b)
{
	t_node	*aux_a;
	t_node	*aux_b;
	int		lst_size_a;
	int		lst_size_b;
	int		max;

	lst_size_a = 0;
	lst_size_b = 0;
	aux_a = a;
	aux_b = b;
	while (aux_a)
	{
		lst_size_a++;
		aux_a = aux_a->next;
	}
	while (aux_b)
	{
		lst_size_b++;
		aux_b = aux_b->next;
	}
	max = lst_size_a > lst_size_b ? lst_size_a : lst_size_b;
	while (max)
	{
		if (a && max <= lst_size_a)
		{
			printf("\t%3d\t", a->value);
			a = a->next;
		}
		else
			printf("\t \t");
		if (b && max <= lst_size_b)
		{
			printf("\t%3d\n", b->value);
			b = b->next;
		}
		else
			printf("\n");
		max--;
	}
	printf("\t___\t\t___\n");
	printf("\t A\t\t B\n");
}

void	print_array(t_push_swap *ps)
{
	int i;

	i = 1;
	while (i <= ps->argc)
	{
		printf("%d ", ps->argv[i]);
		i++;
	}
	printf("\n");
}
