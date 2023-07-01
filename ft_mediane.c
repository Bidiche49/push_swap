/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:35:13 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 17:30:56 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_mediane(t_stack **a, t_stack **b, int m, int cm)
{
	t_stack	*tmp;

	while (ft_count_arg(*b) < m)
	{
		tmp = *a;
		if (tmp->index <= m)
		{
			if (tmp->index < (m / 2) && cm == 2)
				tmp->mediane = 1;
			else
				tmp->mediane = cm;
			ft_push(a, b, "pb\n");
			if (tmp->index < (m / 2) && ft_count_arg(*b) > 1)
				ft_rotate(b, "rb\n");
		}
		else
			ft_rot_or_rev(a, b, m);
	}
}

int	ft_loop_med_a(t_stack **a, t_stack **b, int mediane, int count_mediane)
{
	int		count;
	t_stack	*tmp;
	t_stack	*tmp_b;

	tmp = *a;
	tmp_b = *b;
	count = 0;
	while (tmp != NULL && ft_count_arg(*a) > 3 && tmp->mediane == mediane
		&& mediane != 0)
	{
		if (tmp->mediane == mediane && tmp->new_index <= count_mediane / 2 + 1)
		{
			tmp->mediane = tmp_b->mediane + 1;
			ft_push(a, b, "pb\n");
		}
		else
		{
			ft_rotate_or_rr(a, b);
			count++;
		}
		tmp = *a;
	}
	return (count);
}

int	ft_mediane_a(t_stack **a, t_stack **b)
{
	int			count;
	const int	count_mediane = ft_count_mediane(*a);

	ft_fill_new_index(a, count_mediane, (*a)->mediane, 2);
	count = ft_loop_med_a(a, b, (*a)->mediane, count_mediane);
	if (count == 3)
		count = ft_sort_three_back(a, b);
	while (count > 0)
	{
		ft_rev_or_rrr(a, b);
		count--;
	}
	return (count);
}

void	ft_reverse_med_b(t_stack **a, t_stack **b, int count, int is_first)
{
	while (count > 0 && is_first != 1)
	{
		ft_reverse_total(b, "rrb\n");
		count--;
	}
	if (ft_count_mediane(*a) > 3)
		ft_mediane_a(a, b);
}

void	ft_mediane_b(t_stack **a, t_stack **b, int count_mediane, int is_first)
{
	t_stack			*tmp;
	int				mediane;
	int				count;
	const int		count_arg_b = ft_count_arg(*b);

	tmp = *b;
	mediane = tmp->mediane;
	count = 0;
	while (tmp != NULL && ft_count_arg(*b) > 0
		&& tmp->mediane == mediane && count <= count_arg_b / 2)
	{
		tmp = *b;
		if (tmp->mediane == mediane && tmp->new_index > count_mediane / 2)
			ft_push(b, a, "pa\n");
		else if (tmp->mediane == mediane)
		{
			ft_rotate(b, "rb\n");
			count++;
		}
	}
	ft_reverse_med_b(a, b, count, is_first);
}
