/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:34:49 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 16:04:35 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_node *a, t_node *b, t_push_swap *ps)
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
	if (ps->allow_print_stacks == TRUE)
	{
		printf("\n");
		printf("----------------------------\n");
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
}

void	print_index(t_node *a, t_node *b, t_push_swap *ps)
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
	if (ps->allow_print_stacks == TRUE)
	{
		printf("\n");
		printf("----------------------------\n");
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
				printf("\t%3d\t", a->index);
				a = a->next;
			}
			else
				printf("\t \t");
			if (b && max <= lst_size_b)
			{
				printf("\t%3d\n", b->index);
				b = b->next;
			}
			else
				printf("\n");
			max--;
		}
		printf("\t___\t\t___\n");
		printf("\t A\t\t B\n");
	}
}

void	printArray(int array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d  ", array[i]);
		i++;
	}
	printf("\n");
}
