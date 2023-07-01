/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:38:14 by ntardy            #+#    #+#             */
/*   Updated: 2022/11/22 19:06:33 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_counter_index(t_stack *tmp, t_stack *first, int mediane)
{
	int		counter;
	t_stack	*second;

	counter = 0;
	second = first->next;
	while (second != NULL && second->mediane == mediane)
	{
		if (first->value < second->value)
			counter++;
		second = second->next;
	}
	while (tmp != first)
	{
		if (first->value < tmp->value)
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

void	ft_fill_first_index(t_stack *first)
{
	while (first->mediane == 2)
		first = first->next;
	while (first != NULL && first->mediane == 1)
	{
		first->new_index = first->index;
		first = first->next;
	}
}

void	ft_fill_new_index(t_stack **stack, int nb_arg, int mediane, int ref)
{
	t_stack	*first;
	t_stack	*tmp;
	int		counter;

	first = *stack;
	while (first != NULL && first->mediane == mediane)
	{
		tmp = *stack;
		counter = ft_counter_index(tmp, first, mediane);
		if (first->mediane == 2 && ref == 1)
			ft_fill_first_index(first);
		first->new_index = nb_arg - counter;
		first = first->next;
	}
}
