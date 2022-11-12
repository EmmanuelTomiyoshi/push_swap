/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 13:51:58 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_intmemcpy(void *dest, const void *src, size_t n)
{
	int		*ucdest;
	int		*ucsrc;
	size_t	i;

	ucdest = (int *) dest;
	ucsrc = (int *) src;
	i = 0;
	while (i < n)
	{
		ucdest[i] = ucsrc[i];
		i++;
	}
	return (dest);
}

void	normalize_values(t_push_swap *ps)
{
	ft_intmemcpy(ps->copy_value, ps->int_value, ps->list_size);
	bubble_sort(ps->copy_value, ps->list_size);
	create_index(ps);
	// printArray(ps->map_index, ps->list_size);
}

void	create_index(t_push_swap *ps)
{
	int	index;
	int	i;
	int	j;

	i = 0;
	while (i < ps->list_size)
	{
		j = 0;
		while (j < ps->list_size)
		{
			if (ps->int_value[i] == ps->copy_value[j])
			{
				ps->map_index[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	sort_less_than_six_elements(t_push_swap *ps)
{
	if (ps->list_size == 5)
		sort_five_a(ps);
	else if (ps->list_size == 4)
		sort_four_a(ps);
	else if (ps->list_size == 3)
		sort_three_a(ps);
	else if (ps->list_size == 2)
		sort_two_a(ps);
}

void	sort(t_push_swap *ps)
{
	if (ps->list_size < 6)
		sort_less_than_six_elements(ps);
	else
		radix_sort(ps);
}

int	main(int argc, char *argv[])
{
	t_push_swap	ps;

	check_args(argc, argv);
	init_data(&ps, argc, argv);
	normalize_values(&ps);
	stack_building(&ps);
	print_stacks(ps.stack_a, ps.stack_b, &ps);
	sort(&ps);
	print_stacks(ps.stack_a, ps.stack_b, &ps);
	free_memory(&ps);
	return (0);
}
