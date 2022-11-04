/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:36 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/03 21:08:48 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char *argv[])
{
	check_valid_number(argv);
    insufficient_args(argc);
	check_duplicates(argc, argv);
}

void	check_valid_number(char *argv[])
{
    int		i;
	char	*result;

    i = 1;
    while (argv[i])
    {
        check_is_digit(argv[i]);
		check_limits_int(argv[i]);
        i++;
    }
}

void	insufficient_args(int argc)
{
    if (argc <= 2)
		exit(1);
}

void	check_duplicates(int argc, char *argv[])
{
	int i;
	int j;
	
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
