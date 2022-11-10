/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:53 by etomiyos          #+#    #+#             */
/*   Updated: 2022/11/10 20:40:13 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_arr(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int leftmost, int rightmost)
{
    int pivot;
    int i;
    int j;

    pivot = array[rightmost];
    i = (leftmost - 1);
    j = leftmost;
    while (j < rightmost)
    {
        if (array[j] <= pivot)
        {
            i++;
            // printf("\ndentro: array[i] = %d | array[j] = %d\n",
            // i, array[i], j, array[j]);
            swap_arr(&array[i], &array[j]);
        }
        j++;
    }
    swap_arr(&array[i + 1], &array[rightmost]);
    // printf("\nfora: array[i + 1] = %d | array[%d] = %d\n",
    // i, array[i + 1], rightmost, array[rightmost]);

    return (i + 1);
}

//low = leftmost | high = rightmost
void    quickSort(int array[], int leftmost, int rightmost)
{
    int pi;

    // static int p = 0;

    // printf("\np: %d\n", p);
    // p++;
    // if (p == 1)
    //     printf("low: %d | high: %d\n", leftmost, rightmost);
    if (leftmost < rightmost)
    {
        pi = partition(array, leftmost, rightmost);

        quickSort(array, leftmost, pi - 1);
        quickSort(array, pi + 1, rightmost);
    }
}

void    printArray(int array[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%d  ", array[i]);
        i++;
    }
    printf("\n");
}

t_node	*traverse_stack_index(t_node **node, size_t index)
{
	t_node	*temp;
	int 	i;

	i = 0;
	temp = *node;
	while (i < index)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
		i++;
	}
	return (temp); //remover depois
}

int	count_stack_elements(t_node **node)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *node;
	while (temp)
	{
		if (!temp->next)
			return (i + 1);
		temp = temp->next;
		i++;
	}
	return (0);
}

void	get_center_pivot(t_push_swap *ps)
{
	int *argv;

	argv = create_sub_array(ps);
	// printArray(argv, ps->nelem);
	bubble_sort(argv, ps->nelem);
	// printArray(argv, ps->nelem);
	
	ps->center_pivot = argv[(ps->nelem - 1) / 2];

	//PAREI AQUI
	//vocês acham que entender o contexto é mais importante do que entender toda a frase?preciso ver entre new_argv e argv

	// ps->low = ps->argv[1];
	// ps->high = ps->argv[ps->argc];
}

int	*create_sub_array(t_push_swap *ps)
{
	t_node	*temp;
	int		i;

	i = 0;
	ps->new_argv = ft_calloc(ps->nelem, sizeof(int));
	temp = ps->stack_a;
	while (temp)
	{
		ps->new_argv[i] = temp->value;
		// printf("array[%d] = %d\n", i, ps->new_argv[i]);

		if (!temp->next)
			return (ps->new_argv);

		temp = temp->next;
		i++;
	}
}

void	quick_sort(t_push_swap *ps)
{
	int		last;

	ps->nelem = ps->argc;
	get_center_pivot(ps);
	free(ps->new_argv); // //
	last = ft_lastnode(ps->stack_a)->value;

	while (ps->nelem > 2)
	{
		while (ps->stack_a)
		{
			if (ps->stack_a->value == last)
			{
				run_rotate(ps, "ra");
				break ;
			}
			if (ps->stack_a->value <= ps->center_pivot)
				run_push(ps, "pb");
			else
				run_rotate(ps, "ra");
		}
		if (ps->center_pivot != 7)
			printf("pivot: %d\n", ps->center_pivot);
		ps->nelem = count_stack_elements(&ps->stack_a);
		get_center_pivot(ps);
		free(ps->new_argv); // //
		print_stacks(ps->stack_a, ps->stack_b);
		printf("pivot: %d\n", ps->center_pivot);
	}
}

int	main(int argc, char *argv[])
{
	t_push_swap	ps;
	t_node		*temp;

	check_args(argc, argv);
	init_data(&ps, argc, argv);
	stack_building(&ps);

	print_stacks(ps.stack_a, ps.stack_b);
	quick_sort(&ps);
	// print_stacks(ps.stack_a, ps.stack_b);
	// temp = traverse_stack_index(&ps.stack_a, 0);
	// print_stacks(ps.stack_a, ps.stack_b);
	// get_center_pivot(&ps);
	// quick_sort(&ps, 0, ps.argc - 1);
	// partition(&ps, 0, ps.argc - 1);
	free_memory(&ps);
	return (0);
}

//traverse_stack_index(&ps, 2);