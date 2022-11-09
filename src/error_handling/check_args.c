/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:36 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/09 12:31:41 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char *argv[])
{
	check_valid_number(argv);
	check_insufficient_args(argc);
	check_duplicates(argc, argv);
	check_is_sorted(argc, argv);
}

void	check_valid_number(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		check_is_digit(argv[i]);
		check_limits_int(argv[i]);
		i++;
	}
}

void	check_insufficient_args(int argc)
{
	if (argc <= 2)
		exit(1);
}

void	check_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	argc = argc - 1;
	argv = argv + 1;
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error_message();
			j++;
		}
		i++;
	}
}

void	check_is_sorted(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return ;
		i++;
	}
	exit(1);
}
