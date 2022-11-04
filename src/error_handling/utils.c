/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:42:27 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/03 21:22:45 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_is_digit(char *str)
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

void	check_limits_int(char *str)
{
	if (str[0] == '+')
		str++;
	while (str[0] == '0' && str[1] != '\0')
		str++;
	if (ft_strncmp(ft_itoa(ft_atoi(str)), str, ft_strlen(str)) != 0)
		error_message();
}