/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:20:32 by ntardy            #+#    #+#             */
/*   Updated: 2022/11/18 17:21:02 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char *rab)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	tmp = *stack;
	tmp2 = tmp->next;
	tmp3 = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tmp3;
	tmp->next->next = NULL;
	*stack = tmp2;
	if (rab == NULL)
		return ;
	write(1, rab, 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	write(1, "rr\n", 3);
}

void	ft_reverse_total(t_stack **stack, char *rrab)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = tmp;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = tmp2;
	tmp2 = tmp->next;
	*stack = tmp2;
	tmp->next = NULL;
	if (rrab == NULL)
		return ;
	write(1, rrab, 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_total(a, NULL);
	ft_reverse_total(b, NULL);
	write(1, "rrr\n", 4);
}
