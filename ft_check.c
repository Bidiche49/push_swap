/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:03:51 by ntardy            #+#    #+#             */
/*   Updated: 2022/12/01 18:21:18 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_check(int **a)
{
	write(2, "Error\n", 6);
	free(*a);
	return (0);
}

int	ft_check_wrong(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i] && arg[i] >= '0' && arg[i] <= '9')
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	ft_check_same(int *a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a - 2)
	{
		j = i + 1;
		while (j < size_a - 1)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_arg(int nb_arg, char **arg)
{
	int	i;
	int	*a;

	i = 0;
	a = malloc(sizeof(int) * nb_arg - 1);
	if (!a)
		return (ft_error_check(&a));
	if (nb_arg == 1)
		return (0);
	while (++i < nb_arg)
		if (!ft_check_wrong(arg[i]))
			return (ft_error_check(&a));
	i = 0;
	while (++i < nb_arg)
	{
		if (ft_atoll(arg[i]) >= -2147483648 && ft_atoll(arg[i]) <= 2147483647)
			a[i - 1] = ft_atoll(arg[i]);
		else
			return (ft_error_check(&a));
	}
	if (!ft_check_same(a, nb_arg))
		return (ft_error_check(&a));
	free(a);
	return (1);
}
