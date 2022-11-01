/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:02:36 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/01 18:15:34 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int argc, char *argv[])
{
    insufficient_args(argc);
	check_is_digit(argv);
}

void	insufficient_args(int argc)
{
    if (argc <= 2)
		exit(1);
}

int	check_is_digit(char *argv[])
{
    int	i;

    i = 1;
    while (argv[i])
    {
        if (check_arg_is_digit(argv[i]) == -1)
        {
			ft_printf("Error\n");
			exit(1);
		}
        i++;
    }
    return (0);
}

int	check_arg_is_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1 && (str[i] == '-' || str[i] == '+'))
		return (-1);
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (-1);
	return (0);
}