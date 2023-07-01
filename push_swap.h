/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:29:11 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 17:42:33 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				new_index;
	int				mediane;
	struct s_stack	*next;
}					t_stack;

/*****************************************************/
/*                     atoi.c                        */
/*****************************************************/
long long	ft_atoll(const char *nptr);
int			ft_atoi(const char *nptr);
/*****************************************************/
/*                     check.c                       */
/*****************************************************/
int			ft_check_arg(int nb_arg, char **arg);
/*****************************************************/
/*                  movements.c                      */
/*****************************************************/
void		ft_push(t_stack **stack_src, t_stack **stack_dest, char *pab);
void		ft_swap(t_stack **stack, char *sab);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_swap_or_ss(t_stack **a, t_stack **b);
void		ft_rotate(t_stack **stack, char *rab);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_rotate_or_rr(t_stack **a, t_stack **b);
void		ft_reverse_total(t_stack **stack, char *rrab);
void		ft_rrr(t_stack **a, t_stack **b);
void		ft_rev_or_rrr(t_stack **a, t_stack **b);
void		ft_rot_or_rev(t_stack **a, t_stack **b, int m);
/*****************************************************/
/*                    sorts.c                        */
/*****************************************************/
void		ft_sort(t_stack **a, t_stack **b);
void		ft_sort_six(t_stack **a, t_stack **b);
void		ft_sort_five(t_stack **a, t_stack **b);
void		ft_sort_four(t_stack **a, t_stack **b);
void		ft_sort_three(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_three_top(t_stack **a, t_stack **b);
int			ft_sort_three_back(t_stack **a, t_stack **b);
int			ft_is_sorted(t_stack *stack);
/*****************************************************/
/*                    stack.c                        */
/*****************************************************/
void		ft_fill_new_index(t_stack **s, int n, int m, int r);
int			ft_stackadd_back(t_stack **stack, int value);
t_stack		*ft_fill_stack(int nb_arg, char **arg);
/*****************************************************/
/*                    mediane.c                      */
/*****************************************************/
int			ft_mediane_a(t_stack **a, t_stack **b);
void		ft_first_mediane(t_stack **a, t_stack **b, int m, int cm);
void		ft_mediane_b(t_stack **a, t_stack **b,
				int count_mediane, int is_first);
/*****************************************************/
/*                    utils.c                        */
/*****************************************************/
int			ft_count_mediane(t_stack *stack);
int			ft_count_arg(t_stack *stack);
int			ft_free(t_stack **a);
void		ft_under_four(t_stack **a, t_stack **b);

#endif
