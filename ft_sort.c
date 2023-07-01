/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:35:02 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 17:42:11 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_mediane(t_stack *stack)
{
	int		count;
	t_stack	*tmp_stack;

	tmp_stack = stack;
	count = 0;
	while (tmp_stack->next != NULL && tmp_stack->mediane == stack->mediane)
	{
		count++;
		tmp_stack = tmp_stack->next;
	}
	return (count);
}

void	ft_loop_under_4(t_stack **a, t_stack **b, int mediane)
{
	ft_push(b, a, "pa\n");
	while (ft_count_arg(*b) > 0
		&& (*b)->mediane == mediane && ft_count_mediane(*a) < 3)
		ft_push(b, a, "pa\n");
}

void	ft_loop_four(t_stack **a, t_stack **b)
{
	while (ft_count_arg(*b) > 1)
	{
		if ((*b)->index == 1)
			ft_rotate(b, "rb\n");
		ft_push(b, a, "pa\n");
	}
	ft_sort_three_top(a, b);
}

void	ft_step_sort(t_stack **a, t_stack **b)
{
	int	is_first;
	int	reverse_med;

	while (ft_count_arg(*b) > 0)
	{
		if ((*b)->mediane == 1)
			is_first = 1;
		else
			is_first = 0;
		if (ft_count_arg(*b) == 4)
			ft_loop_four(a, b);
		if (ft_count_mediane(*b) < 4)
			ft_loop_under_4(a, b, (*b)->mediane);
		else if ((*a)->mediane != 0 && ft_count_mediane(*a) > 3)
			while (ft_count_mediane(*a) > 3)
				reverse_med = ft_mediane_a(a, b);
		else
			ft_mediane_b(a, b, ft_count_mediane(*b), is_first);
		if (ft_count_mediane(*a) <= 3)
			ft_sort_three_top(a, b);
		(void)reverse_med;
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int		median;
	int		count_mediane;

	count_mediane = 2;
	median = 0;
	while (!ft_is_sorted(*a))
	{
		median = median + (ft_count_arg(*a) / 2) + (ft_count_arg(*a) % 2);
		ft_first_mediane(a, b, median, count_mediane);
		ft_fill_new_index(b, ft_count_mediane(*b), count_mediane, 1);
		count_mediane++;
		ft_under_four(a, b);
	}
	ft_step_sort(a, b);
}
