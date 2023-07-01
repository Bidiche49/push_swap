/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:07:33 by ntardy            #+#    #+#             */
/*   Updated: 2022/11/22 19:33:41 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_src, t_stack **stack_dest, char *pab)
{
	t_stack	*tmp;

	if (*stack_src == NULL)
		return ;
	tmp = *stack_src;
	*stack_src = tmp->next;
	if (stack_dest == NULL)
	{
		tmp->next = NULL;
		*stack_dest = tmp;
	}
	else
	{
		tmp->next = *stack_dest;
		*stack_dest = tmp;
	}
	write(1, pab, 3);
}

void	ft_swap(t_stack **stack, char *sab)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*stack = tmp2;
	if (sab == NULL)
		return ;
	write(1, sab, 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	write(1, "ss\n", 3);
}
