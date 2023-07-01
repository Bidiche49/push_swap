/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:05:58 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 17:34:30 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_under_four(t_stack **a, t_stack **b)
{
	if (ft_count_arg(*a) == 3)
		ft_sort_three(a, b);
	else if (ft_count_arg(*a) == 2)
		if (!ft_is_sorted(*a))
			ft_swap_or_ss(a, b);
}

void	ft_swap_or_ss(t_stack **a, t_stack **b)
{
	if ((*b) == NULL)
	{
		ft_swap(a, "sa\n");
		return ;
	}
	if (ft_count_arg(*b) > 1 && (*b)->mediane == (*b)->next->mediane
		&& (*b)->value < (*b)->next->value)
		ft_ss(a, b);
	else
		ft_swap(a, "sa\n");
}

void	ft_rotate_or_rr(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = *b;
	if ((*b) == NULL)
	{
		ft_rotate(a, "ra\n");
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	if (ft_count_arg(*b) > 1 && (*b)->value < last->value)
		ft_rr(a, b);
	else
		ft_rotate(a, "ra\n");
}

void	ft_rev_or_rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = *b;
	if ((*b) == NULL)
	{
		ft_reverse_total(a, "rra\n");
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	if (ft_count_arg(*b) > 1 && (*b)->value < last->value)
		ft_rrr(a, b);
	else
		ft_reverse_total(a, "rra\n");
}

void	ft_rot_or_rev(t_stack **a, t_stack **b, int m)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->index <= m)
		ft_rev_or_rrr(a, b);
	else
		ft_rotate_or_rr(a, b);
}
