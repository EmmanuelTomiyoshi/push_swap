// int	partition(t_push_swap *ps, int low, int high)
// {
// 	int pivot;
// 	int i;
// 	int j;
// 	int aux;
// 	t_node *temp;

// 	// temp = traverse_stack_index(&ps->stack_a, 1);
// 	// printf("value: %d\n", temp->value);

// 	pivot = ps->center_pivot;
// 	// printf("pivot: %d\n", pivot);

// 	i = (low - 1);
// 	j = low;
// 	aux = traverse_stack_index(&ps->stack_a, j)->value;
// 	while (j < high)
// 	{
// 		if (aux <= pivot)
// 		{
// 			i++;
// 			temp = traverse_stack_index(&ps->stack_a, i);

// 			// swap(&array[i], &array[j]);
// 			run_push(ps, "pb");
// 		}
// 		j++;
// 	}
// 	temp = traverse_stack_index(&ps->stack_a, (i + 1));
// 	//swap(&array[i + 1], &array[rightmost]);
// 	//swap(ps, &temp); //

// 	return (i + 1);
// }
// //swap(node1, node2)

// //7 6 ->
// //6 7

// //7 6 5 4 3 2 1
// //i = 7 | j = 1;

// void	quick_sort(t_push_swap *ps, int low, int high)
// {
// 	int pi;

// 	if (low < high)
// 	{
// 		pi = partition(ps, low, high);
		
// 		quick_sort(ps, low, pi - 1);
// 		quick_sort(ps, pi + 1, high);
// 	}
// }
