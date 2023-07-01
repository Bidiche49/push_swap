/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4_5_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:27:53 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 17:38:55 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_six(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_count_arg(*b) < 3)
	{
		tmp = *a;
		if (tmp->index > 3)
			ft_rotate_or_rr(a, b);
		else
			ft_push(a, b, "pb\n");
	}
	if (!ft_is_sorted(*a))
		ft_sort_three(a, b);
	while (ft_count_arg(*b) > 0)
		ft_push(b, a, "pa\n");
	if (!ft_is_sorted(*a))
		ft_sort_three_top(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_count_arg(*b) < 2)
	{
		tmp = *a;
		if (tmp->index > 2)
			ft_rotate_or_rr(a, b);
		else
			ft_push(a, b, "pb\n");
	}
	if (!ft_is_sorted(*a))
		ft_sort_three(a, b);
	while (ft_count_arg(*b) > 0)
		ft_push(b, a, "pa\n");
	if (!ft_is_sorted(*a))
		ft_swap_or_ss(a, b);
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_count_arg(*b) < 1)
	{
		tmp = *a;
		if (tmp->index != 1)
			ft_rotate_or_rr(a, b);
		else
			ft_push(a, b, "pb\n");
	}
	if (!ft_is_sorted(*a))
		ft_sort_three(a, b);
	ft_push(b, a, "pa\n");
}
