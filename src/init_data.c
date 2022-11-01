/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:17:32 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/01 17:19:17 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_push_swap *ps, int argc, char *argv[])
{
	ps->argc = argc - 1;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	argv_atoi(ps, argv);
}

void	argv_atoi(t_push_swap *ps, char *argv[])
{
	int i;
	
	i = 1;
	ps->argv = ft_calloc(sizeof(char *), ps->argc + 1);
	while (i <= ps->argc)
	{
		ps->argv[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	stack_building(t_push_swap *ps)
{
	int i;

	i = 1;
	ps->stack_a = ft_newnode(ps->argv[i]);
	while (i < ps->argc)
	{
		ft_nodeadd_back(&ps->stack_a, ft_newnode(ps->argv[i + 1]));
		i++;
	}
    print_stacks(ps->stack_a, ps->stack_b);
}