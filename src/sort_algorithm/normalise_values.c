/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:15:59 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 16:48:56 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_values(t_push_swap *ps)
{
	ft_intmemcpy(ps->copy_value, ps->int_value, ps->list_size);
	bubble_sort(ps->copy_value, ps->list_size);
	create_index(ps);
}

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

void	create_index(t_push_swap *ps)
{
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
		sort_five(ps);
	else if (ps->list_size == 4)
		sort_four(ps);
	else if (ps->list_size == 3)
		sort_three(ps);
	else if (ps->list_size == 2)
		sort_two(ps);
}

void	sort(t_push_swap *ps)
{
	if (ps->list_size < 6)
		sort_less_than_six_elements(ps);
	else
		radix(ps);
}
