

// void	quick_sort(t_push_swap *ps);
// void	divide_by_pivot(t_push_swap *ps, t_node *stack);
// void	divide_to_conquer(t_push_swap *ps, t_node *left_stack, t_node *right_stack);
// int		*create_sub_array(t_push_swap *ps, t_node *stack);
// void	get_center_pivot(t_push_swap *ps, t_node *stack);
// void	init_element_data(t_push_swap *ps, t_node *stack);
// void	choose_best_method(t_push_swap *ps);

// int	*create_sub_array(t_push_swap *ps, t_node *stack)
// {
// 	t_node	*temp;
// 	int		i;

// 	i = 0;
// 	ps->new_argv = ft_calloc(ps->nelem, sizeof(int));
// 	temp = stack;
// 	while (temp)
// 	{
// 		ps->new_argv[i] = temp->value;
// 		if (!temp->next)
// 			return (ps->new_argv);
// 		temp = temp->next;
// 		i++;
// 	}
// }

// void	divide_by_pivot(t_push_swap *ps, t_node *stack)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < ps->nelem)
// 	{
// 		if (stack->value <= ps->center_pivot) //ps->stack->value
// 		{
// 			printf("oi\n");
// 			run_push(ps, "pb");
// 		}
// 		else
// 		{
// 			// printf("tchau\n");
// 			run_rotate(ps, "ra");
// 		}
// 		i++;
// 	}
// 	if (!is_sorted(&stack))
// 	{
// 		run_swap(ps, "sa");
// 	}
// 	print_stacks(ps->stack_a, ps->stack_b, ps);
// }

// void	method_a(t_push_swap *ps)
// {
// 	if (ps->nelem == 5)
// 		sort_five_a(ps);
// 	else if (ps->nelem == 4)
// 		sort_four_a(ps);
// 	else if (ps->nelem == 3)
// 		sort_three_a(ps);
// 	print_stacks(ps->stack_a, ps->stack_b, ps);
// }

// // void	method_b(t_push_swap *ps)
// // {
// // 	if (ps->nelem == 5)
// // 		sort_five_b(ps);
// // 	else if (ps->nelem == 4)
// // 		sort_four_b(ps);
// // 	else if (ps->nelem == 3)
// // 		sort_three_b(ps);
// // 	print_stacks(ps->stack_a, ps->stack_b, ps);
// // }

// void	choose_best_method(t_push_swap *ps)
// {
// 	method_a(ps);
// }

// void	get_center_pivot(t_push_swap *ps, t_node *stack)
// {
// 	int	*argv;

// 	argv = create_sub_array(ps, ps->stack_a);
// 	printArray(argv, ps->nelem);
// 	bubble_sort(argv, ps->nelem);
// 	printf("nelem: %d\n", ps->nelem);
// 	ps->center_pivot = argv[(ps->nelem - 1) / 2];
// 	printf("pivot: %d\n", ps->center_pivot);
// }

// void	init_element_data(t_push_swap *ps, t_node *stack)
// {
// 	ps->nelem = ps->argc;
// 	printf("nelem: %d\n", ps->nelem);
// 	get_center_pivot(ps, ps->stack_a);
// 	printf("pivot: %d\n", ps->center_pivot);
// 	free(ps->new_argv);
// }

// void	divide_to_conquer(t_push_swap *ps, t_node *left_stack, t_node *right_stack)
// {
// 	init_element_data(ps, ps->stack_a);
// 	// while (ps->nelem > 5)
// 	// {
	
// 		divide_by_pivot(ps, ps->stack_a->next);
// 		ps->nelem = count_node_elements(&ps->stack_a);
// 		printf("nelem: %d\n", ps->nelem);
// 		// get_center_pivot(ps, left_stack);
// 		// free(ps->new_argv);
// 		// print_stacks(ps->stack_a, ps->stack_b, ps);
// 		// printf("pivot: %d\n", ps->center_pivot);
// 	// }
// 	// choose_best_method(ps);

	
// 	//recursiva divide_to_conquer right, left
// }

// void	quick_sort(t_push_swap *ps)
// {
// 	divide_to_conquer(ps, ps->stack_a, ps->stack_b);
// }



// //outros

// // void	divide_to_conquer(t_push_swap *ps)
// // {
// // 	int	last;
// // 	int i;

// // 	ps->nelem = ps->argc;
// // 	get_center_pivot(ps);
// // 	printf("pivot: %d\n", ps->center_pivot);
// // 	free(ps->new_argv);
// // 	last = ft_lastnode(ps->stack_a)->value;
// // 	while (ps->nelem > 2) // > 5, sort_five()
// // 	{
// // 		i = 0;
// // 		while (i < ps->nelem)
// // 		{
// // 			if (ps->stack_a->value <= ps->center_pivot)
// // 				run_push(ps, "pb");
// // 			else
// // 				run_rotate(ps, "ra");
// // 			i++;
// // 		}
// // 		if (!is_sorted(&ps->stack_a))
// // 			run_swap(ps, "sa");
// // 		ps->nelem = count_node_elements(&ps->stack_a);
// // 		get_center_pivot(ps);
// // 		free(ps->new_argv); // //
// // 		print_stacks(ps->stack_a, ps->stack_b, ps);
// // 		printf("pivot: %d\n", ps->center_pivot);
// // 	}
// // }

// 	// int	top_stack_a;
	
// 	// while (ps->stack_b)
// 	// {
// 	// 	if (!ps->stack_b->next)
// 	// 	{
// 	// 		run_rotate(ps, "ra");
// 	// 		run_push(ps, "pa");
// 	// 		print_stacks(ps->stack_a, ps->stack_b, ps);
// 	// 		break ;
// 	// 	}
// 	// 	top_stack_a = ps->stack_a->value;
// 	// 	// printf("top_stack_a: %d | ", top_stack_a);
// 	// 	// printf("top_stack_b: %d\n", ps->stack_b->value);
// 	// 	if (top_stack_a > ps->stack_b->value)
// 	// 		run_push(ps, "pa");
// 	// 	else if (top_stack_a < ps->stack_b->value)
// 	// 	{
// 	// 		run_rotate(ps, "ra");
// 	// 		run_push(ps, "pb");
// 	// 	}
// 	// 	else
// 	// 		break ;
// 	// 	print_stacks(ps->stack_a, ps->stack_b, ps);
// 	// }

// 	// // while (!is_sorted(ps))
// 	// // {
// 	// // 	run_rotate_reverse(ps, "rra");
// 	// // }
// 	// print_stacks(ps->stack_a, ps->stack_b, ps);

// 	// //rotate the last two
// 	// if (!is_sorted(&ps->stack_a))
// 	// {
// 	// 	run_rotate(ps, "ra");
// 	// }
// 	// print_stacks(ps->stack_a, ps->stack_b, ps);