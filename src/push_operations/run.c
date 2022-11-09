/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:01:18 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/09 18:01:20 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_push(t_push_swap *ps, char *operation)
{
	if (ps->allow_print_ops == TRUE)
        ft_putendl_fd(operation, 1);
    if (ft_strncmp("pa", operation, ft_strlen(operation)) == 0)
        push(ps, &ps->stack_b, &ps->stack_a);
    else if (ft_strncmp("pb", operation, ft_strlen(operation)) == 0)
        push(ps, &ps->stack_a, &ps->stack_b);
}

void	run_swap(t_push_swap *ps, char *operation)
{
    if (ps->allow_print_ops == TRUE)
        ft_putendl_fd(operation, 1);
    if (ft_strncmp("sa", operation, ft_strlen(operation)) == 0)
        swap(ps, &ps->stack_a);
    else if (ft_strncmp("sb", operation, ft_strlen(operation)) == 0)
        swap(ps, &ps->stack_b);
    else if (ft_strncmp("ss", operation, ft_strlen(operation)) == 0)
    {
        swap(ps, &ps->stack_a);
        swap(ps, &ps->stack_b);
    }
}

void	run_rotate(t_push_swap *ps, char *operation)
{
	if (ps->allow_print_ops == TRUE)
        ft_putendl_fd(operation, 1);
	if (ft_strncmp("ra", operation, ft_strlen(operation)) == 0)
        rotate(ps, &ps->stack_a);
    else if (ft_strncmp("rb", operation, ft_strlen(operation)) == 0)
        rotate(ps, &ps->stack_b);
    else if (ft_strncmp("rr", operation, ft_strlen(operation)) == 0)
    {
        rotate(ps, &ps->stack_a);
        rotate(ps, &ps->stack_b);
    }
}

void	run_rotate_reverse(t_push_swap *ps, char *operation)
{
	if (ps->allow_print_ops == TRUE)
        ft_putendl_fd(operation, 1);
	if (ft_strncmp("rra", operation, ft_strlen(operation)) == 0)
        rotate_reverse(ps, &ps->stack_a);
    else if (ft_strncmp("rrb", operation, ft_strlen(operation)) == 0)
        rotate_reverse(ps, &ps->stack_b);
    else if (ft_strncmp("rrr", operation, ft_strlen(operation)) == 0)
    {
        rotate_reverse(ps, &ps->stack_a);
        rotate_reverse(ps, &ps->stack_b);
    }
}
