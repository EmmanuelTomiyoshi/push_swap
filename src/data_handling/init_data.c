/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:17:32 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 13:15:08 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_push_swap *ps, int argc, char *argv[])
{
	ps->allow_print_ops = FALSE;
	ps->allow_print_stacks = TRUE;
	ps->argc = argc - 1;
	ps->list_size = ps->argc;
	ps->copy_value = ft_calloc(sizeof(int), ps->argc);
	ps->map_index = ft_calloc(sizeof(int), ps->argc);
	ps->center_pivot = MAX_INT;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	argv_atoi(ps, argv);
}

void	argv_atoi(t_push_swap *ps, char *argv[])
{
	int	i;

	i = 0;
	ps->argv = ft_calloc(sizeof(int), ps->argc);
	ps->int_value = ft_calloc(sizeof(int), ps->argc);
	while (i < ps->argc)
	{
		ps->argv[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ps->int_value = ps->argv;
}

void	stack_building(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i < ps->argc)
	{
		ft_nodeadd_back(&ps->stack_a, ft_newnode(ps->argv[i], ps->map_index[i]));
		i++;
	}
}
