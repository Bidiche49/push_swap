/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:39:19 by ntardy            #+#    #+#             */
/*   Updated: 2022/11/30 17:21:02 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	int		b;
	int		c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a > c && b > c)
	{
		ft_rotate_or_rr(stack_a, stack_b);
		ft_swap_or_ss(stack_a, stack_b);
	}
	else if (a < b && a < c && b > c)
	{
		ft_swap_or_ss(stack_a, stack_b);
		ft_rotate_or_rr(stack_a, stack_b);
	}
	else if (a < b)
		ft_rev_or_rrr(stack_a, stack_b);
	else if (a < c)
		ft_swap_or_ss(stack_a, stack_b);
	else
		ft_rotate_or_rr(stack_a, stack_b);
}

void	ft_first_step(t_stack **a, t_stack **b, t_stack *tmp)
{
	if (tmp->index > tmp->next->next->index)
	{
		ft_swap_or_ss(a, b);
		ft_rotate_or_rr(a, b);
		ft_swap_or_ss(a, b);
		ft_rev_or_rrr(a, b);
		tmp = *a;
	}
	if (tmp->index > tmp->next->index)
		ft_swap_or_ss(a, b);
}

void	ft_second_step(t_stack **a, t_stack **b, t_stack *tmp)
{
	if (tmp->next->next->index < tmp->index && tmp->index < tmp->next->index)
	{
		ft_rotate_or_rr(a, b);
		ft_swap_or_ss(a, b);
		ft_rev_or_rrr(a, b);
		ft_swap_or_ss(a, b);
	}
	else if (!ft_is_sorted(*a))
	{
		ft_rotate_or_rr(a, b);
		ft_swap_or_ss(a, b);
		ft_rev_or_rrr(a, b);
	}
}

void	ft_sort_three_top(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	if (ft_count_mediane(*a) == 2)
	{
		if (!ft_is_sorted(*a))
			ft_swap_or_ss(a, b);
	}
	else if (tmp->index > tmp->next->index)
		ft_first_step(a, b, tmp);
	else
		ft_second_step(a, b, tmp);
	tmp = *a;
	while (tmp->mediane != 0)
	{
		tmp->mediane = 0;
		tmp = tmp->next;
	}
}
