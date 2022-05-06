/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:22 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:22 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test_stack(t_stack *a, t_stack *b, t_stack *test_stack, int tryhard)
{
	t_iscore	best;
	t_iscore	act;
	t_dint		move;

	best.score = INT_MAX;
	move.brot = 0;
	act.index = 0;
	while (act.index < a->len)
	{
		test_stack = ft_copy_stack(a);
		act.score = 0;
		if (act.index < a->len / 2)
			move.arot = act.index;
		else
			move.arot = 0 - (a->len - act.index);
		ft_rotate_xfor(test_stack, b, &move, &act.score);
		ft_sort_big_stack(test_stack, b, &act.score);
		if (act.score < best.score)
			best = act;
		ft_free_stack(test_stack);
		act.index += tryhard;
	}
	ft_test_stack2(a, b, &best, &move);
}

void	ft_test_stack2(t_stack *a, t_stack *b, t_iscore *best, t_dint *move)
{
	if (best->index >= a->len / 2)
		best->index = 0 - (a->len - best->index);
	move->arot = best->index;
	ft_rotate_xfor(a, b, move, NULL);
}

void	ft_sort_big_stack(t_stack *a, t_stack *b, int *print)
{
	int		m_nb;
	int		best_a;
	t_dint	rots;

	while (a->len > 0)
	{
		m_nb = INT_MAX;
		ft_big_stack_choose(a, b, &m_nb, &best_a);
		rots.brot = m_nb;
		if (best_a > a->len / 2)
			rots.arot = 0 - (a->len - best_a);
		else
			rots.arot = best_a;
		ft_rotate_xfor(a, b, &rots, print);
		ft_take_stack(b, a, print);
	}
	ft_big_stack_finish(a, b, print);
}

void	ft_big_stack_choose(t_stack *a, t_stack *b, int *m_nb, int *best_a)
{
	int	i;

	i = 0;
	while (i <= a->len / 2 && a->len > 3)
	{
		if (ft_abs(ft_place_inv(b, a->n[i])) + i < ft_abs(*m_nb))
			*best_a = i;
		if (ft_abs(ft_place_inv(b, a->n[i])) + i < ft_abs(*m_nb))
			*m_nb = ft_place_inv(b, a->n[i]);
		if (i != a->len / 2 && ft_abs(ft_place_inv(b, a->n[(a->len - 1) - i]))
			+ i + 1 < ft_abs(*m_nb))
		{
			*m_nb = ft_place_inv(b, a->n[(a->len - 1) - i]);
			*best_a = (a->len - 1) - i;
		}
		i++;
	}
	while (i < a->len && a->len <= 3)
	{
		if (ft_abs(ft_place_inv(b, a->n[i])) + i < ft_abs(*m_nb))
			*best_a = i;
		if (ft_abs(ft_place_inv(b, a->n[i])) + i < ft_abs(*m_nb))
			*m_nb = ft_place_inv(b, a->n[i]);
		i++;
	}
}

void	ft_big_stack_finish(t_stack *a, t_stack *b, int *print)
{
	while (b->len > 0)
		ft_take_stack(a, b, print);
	while (a->n[0] > 0)
	{
		if (a->n[0] < a->len / 2)
			ft_rrotate_stack(a, print);
		else
			ft_rotate_stack(a, print);
	}
}
