/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:03:43 by ntardy            #+#    #+#             */
/*   Updated: 2022/11/30 17:17:06 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	step_1(t_stack **a, t_stack **b)
{
	ft_rev_or_rrr(a, b);
	ft_rev_or_rrr(a, b);
	ft_swap_or_ss(a, b);
	ft_rev_or_rrr(a, b);
	ft_swap_or_ss(a, b);
	return (0);
}

int	step_2(t_stack **a, t_stack **b)
{
	ft_rev_or_rrr(a, b);
	ft_rev_or_rrr(a, b);
	ft_swap_or_ss(a, b);
	ft_push(a, b, "pb\n");
	ft_rev_or_rrr(a, b);
	ft_swap_or_ss(a, b);
	ft_push(b, a, "pa\n");
	return (0);
}

int	ft_sort_three_back(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	if (ft_count_arg(*a) < 4)
		return (3);
	while (first->mediane == 0)
		first = first->next;
	second = first->next;
	third = second->next;
	if (first->value < second->value && third->value < first->value)
		return (step_1(a, b));
	if (first->value > second->value && second->value > third->value)
		return (step_2(a, b));
	return (3);
}
