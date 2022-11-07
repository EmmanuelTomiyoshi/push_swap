/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:37:50 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/07 09:14:33 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int argc, char **argv, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = argc - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (ft_atoi(argv[mid]) == target)
			return (mid);
		else if (target < ft_atoi(argv[mid]))
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

// int main(int argc, char **argv)
// {
//     int target;
//     int result;
	
//     target = 40;
//     result = binary_search(argc, argv, target);
//     printf("elemento é: %d\n", result);
//     return (0);
// }
