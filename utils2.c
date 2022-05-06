/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:10:06 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/12/10 15:10:06 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int	ft_smallest_index(t_stack *s)
{
	int	i;
	int	smallest_index;
	int	smallest_value;

	smallest_index = 0;
	smallest_value = s->n[0];
	i = 1;
	while (i < s->len)
	{
		if (s->n[i] < smallest_value)
		{
			smallest_index = i;
			smallest_value = s->n[i];
		}
		i++;
	}
	return (smallest_index);
}

int	ft_biggest_index(t_stack *s)
{
	int	i;
	int	biggest_index;
	int	biggest_value;

	biggest_index = 0;
	biggest_value = s->n[0];
	i = 1;
	while (i < s->len)
	{
		if (s->n[i] > biggest_value)
		{
			biggest_index = i;
			biggest_value = s->n[i];
		}
		i++;
	}
	return (biggest_index);
}

int	ft_place_inv(t_stack *s, int search)
{
	int	i;

	i = 0;
	if (s->len < 2)
		return (0);
	if (search > s->n[ft_biggest_index(s)])
		i = ((ft_biggest_index(s)) % s->len);
	else if (search < s->n[ft_smallest_index(s)])
		i = ((ft_smallest_index(s) + 1) % s->len);
	else
	{
		while (i < s->len && search > s->n[i])
			i++;
		while (i < s->len && search < s->n[i])
			i++;
	}
	if (i % s->len <= s->len / 2)
		return ((i) % s->len);
	else
		return (0 - (s->len - ((i) % s->len)));
}

void	ft_sort_very_small_stack(t_stack *a, int *print)
{
	while (ft_verify_stack(a) == -2)
	{
		if (a->n[0] == a->n[1] + 1)
			ft_swap_stack(a, print);
		else
			ft_rrotate_stack(a, print);
	}
	while (ft_smallest_index(a) > 0)
	{
		if (ft_smallest_index(a) <= a->len)
			ft_rrotate_stack(a, print);
		else
			ft_rotate_stack(a, print);
	}
}
