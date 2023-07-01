/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:50:51 by ntardy            #+#    #+#             */
/*   Updated: 2022/11/18 17:48:15 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stackadd_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*actual;

	actual = *stack;
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->value = value;
	new->next = NULL;
	new->mediane = 0;
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = new;
	return (1);
}

int	ft_counter(t_stack *first, t_stack *second, t_stack *tmp)
{
	int		counter;

	counter = 0;
	while (second != NULL)
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

void	ft_fill_index(t_stack **stack, int nb_arg)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	first = *stack;
	while (first != NULL)
	{
		tmp = *stack;
		second = first->next;
		first->index = nb_arg - ft_counter(first, second, tmp);
		first = first->next;
	}
}

t_stack	*ft_fill_stack(int nb_arg, char **arg)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->value = ft_atoi(arg[1]);
	stack->next = NULL;
	i = 1;
	while (++i < nb_arg)
	{
		if (!ft_stackadd_back(&stack, ft_atoi(arg[i])))
			return (NULL);
	}
	ft_fill_index(&stack, nb_arg - 1);
	return (stack);
}
