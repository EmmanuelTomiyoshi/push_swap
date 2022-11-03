/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:36 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/03 20:10:49 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

#define MAX_INT +2147483647
#define MIN_INT -2147483648

void	check_args(int argc, char *argv[])
{
	check_is_digit(argv);
    insufficient_args(argc);
	check_duplicates(argc, argv);
}

void	error_message()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	insufficient_args(int argc)
{
    if (argc <= 2)
		exit(1);
}

void	check_is_digit(char *argv[])
{
    int		i;
	char	*result;

    i = 1;
    while (argv[i])
    {
        check_arg_is_digit(argv[i]);
		check_limits_int(argv[i]);
        i++;
    }
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

void	check_limits_int(char *str)
{
	if (str[0] == '+')
		str++;
	while (str[0] == '0' && str[1] != '\0')
		str++;
	if (ft_strncmp(ft_itoa(ft_atoi(str)), str, ft_strlen(str)) != 0)
		error_message();
}

void	check_arg_is_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1 && (str[i] == '-' || str[i] == '+'))
		error_message();
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		error_message();
}