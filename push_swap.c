/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:27:35 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 17:42:40 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_count_arg(t_stack *stack)
{
	int	counter;

	counter = 0;
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		counter++;
		stack = stack->next;
	}
	return (counter + 1);
}

void	ft_choose_algo(t_stack **stack_a, t_stack **stack_b)
{
	const int	counter = ft_count_arg(*stack_a);

	if (counter == 2)
		ft_swap(stack_a, "sa\n");
	else if (counter == 3)
		ft_sort_three(stack_a, stack_b);
	else if (counter == 4)
		ft_sort_four(stack_a, stack_b);
	else if (counter == 5)
		ft_sort_five(stack_a, stack_b);
	else if (counter == 6)
		ft_sort_six(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!ft_check_arg(argc, argv))
		return (0);
	stack_a = ft_fill_stack(argc, argv);
	if (stack_a == NULL)
	{
		ft_free(&stack_a);
		return (0);
	}
	if (ft_is_sorted(stack_a))
	{
		ft_free(&stack_a);
		return (0);
	}
	ft_choose_algo(&stack_a, &stack_b);
	ft_free(&stack_a);
	return (0);
}
