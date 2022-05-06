/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:22 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:22 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_stack(t_stack *a, t_stack *b, int *print)
{
	while (ft_verify_stack(a) == -2)
	{
		if (ft_smallest_index(a) == 0)
			ft_take_stack(b, a, print);
		else if (ft_smallest_index(a) <= a->len / 2)
			ft_rotate_stack(a, print);
		else
			ft_rrotate_stack(a, print);
	}
	while (ft_smallest_index(a) > 0)
	{
		if (ft_smallest_index(a) <= a->len / 2)
			ft_rotate_stack(a, print);
		else
			ft_rrotate_stack(a, print);
	}
	while (b->len > 0)
		ft_take_stack(a, b, print);
}

void	ft_prep_big_stack(t_stack *a, t_stack *b, int tryhard)
{
	ft_chunk_stack(a, b);
	ft_test_stack(a, b, NULL, tryhard);
	ft_take_stack(b, a, NULL);
	ft_take_stack(b, a, NULL);
	if (a->n[0] > b->n[0] && a->n[0] > b->n[1] && b->n[0] < b->n[1])
		ft_rotate_stack(b, NULL);
	else if (a->n[0] < b->n[0] && a->n[0] > b->n[1])
		ft_rotate_stack(b, NULL);
	else if (a->n[0] < b->n[0] && a->n[0] < b->n[1] && b->n[0] < b->n[1])
		ft_rotate_stack(b, NULL);
	ft_take_stack(b, a, NULL);
	ft_sort_big_stack(a, b, NULL);
}

void	ft_chunk_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	med;

	med = a->len / 2;
	i = a->len;
	while (i > 0)
	{
		if (a->n[0] < med)
			ft_take_stack(b, a, NULL);
		else
			ft_rotate_stack(a, NULL);
		i--;
	}
	while (b->len > 0)
		ft_take_stack(a, b, NULL);
}
