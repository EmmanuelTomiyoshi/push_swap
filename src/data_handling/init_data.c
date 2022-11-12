/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:17:32 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/12 15:52:51 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_position_sizes(t_push_swap *ps, int argc)
{
	ps->allow_print_ops = TRUE; // >
	ps->allow_print_stacks = FALSE; // >
	ps->argc = argc - 1;
	ps->list_size = ps->argc;
	ps->center_pivot = MAX_INT;
}

void	init_dynamic_data(t_push_swap *ps)
{
	ps->copy_value = ft_calloc(sizeof(int), ps->argc);
	ps->map_index = ft_calloc(sizeof(int), ps->argc);
	ps->argv = ft_calloc(sizeof(int), ps->argc);
	ps->int_value = ft_calloc(sizeof(int), ps->argc);
	ps->stack_a = NULL;
	ps->stack_b = NULL;
}

void	init_data(t_push_swap *ps, int argc, char *argv[])
{
	init_position_sizes(ps, argc);
	init_dynamic_data(ps);
	init_parsed_argv(ps, argv);
}

void	init_parsed_argv(t_push_swap *ps, char *argv[])
{
	int	i;

	i = 0;
	while (i < ps->argc)
	{
		ps->argv[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	free(ps->int_value); //
	ps->int_value = ps->argv;
}

void	build_stack(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i < ps->argc)
	{
		ft_nodeadd_back(&ps->stack_a, ft_newnode(ps->argv[i], ps->map_index[i]));
		i++;
	}
}
