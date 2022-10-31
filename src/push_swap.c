/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/10/31 15:40:05 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_push_swap *ps, int argc)
{
	ps->argc = argc - 1;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
}

void	check_args(int argc)
{
	if (argc < 2)
		exit(1);
}

int	main(int argc, char *argv[])
{
	t_push_swap ps;
	int i;

	i = 1;
	check_args(argc);
	init_data(&ps, argc);
	ps.stack_a = ft_newnode(ft_atoi(argv[i]));
	while (i < ps.argc)
	{
		ft_nodeadd_back(&ps.stack_a, ft_newnode(ft_atoi(argv[i + 1])));
		i++;
	}
	print_stacks(ps.stack_a, ps.stack_b);
    ft_clearnode(ps.stack_a);
    ft_clearnode(ps.stack_b);
    
    return (0);
}