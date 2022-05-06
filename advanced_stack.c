/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:21 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:21 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_copy_stack(t_stack *s)
{
	t_stack	*new;
	int		i;

	new = malloc(sizeof(t_stack));
	new->id = 'e';
	new->len = s->len;
	new->n = malloc(s->len * sizeof(int));
	i = 0;
	while (i < s->len)
	{
		new->n[i] = s->n[i];
		i++;
	}
	return (new);
}

int	ft_take_stack(t_stack *taker, t_stack *giver, int *print)
{
	if (giver->len < 1)
		return (0);
	if (print == NULL)
		ft_write_move("p", taker->id);
	else
		(*print)++;
	return (ft_push_stack(taker, ft_pop_stack(giver)));
}

int	ft_swap_stack(t_stack *s, int *print)
{
	int	temp;

	if (s->len < 2)
		return (0);
	temp = s->n[0];
	s->n[0] = s->n[1];
	s->n[1] = temp;
	if (print == NULL)
		ft_write_move("s", s->id);
	else
		(*print)++;
	return (1);
}

int	ft_rotate_stack(t_stack *s, int *print)
{
	int	i;
	int	temp;

	if (s->len < 2)
		return (1);
	i = 0;
	temp = s->n[0];
	while (i < s->len - 1)
	{
		s->n[i] = s->n[i + 1];
		i++;
	}
	s->n[s->len - 1] = temp;
	if (print == NULL)
		ft_write_move("r", s->id);
	else
		(*print)++;
	return (1);
}

int	ft_rrotate_stack(t_stack *s, int *print)
{
	int	i;
	int	temp;

	if (s->len < 2)
		return (1);
	i = s->len - 1;
	temp = s->n[s->len - 1];
	while (i > 0)
	{
		s->n[i] = s->n[i - 1];
		i--;
	}
	s->n[0] = temp;
	if (print == NULL)
		ft_write_move("rr", s->id);
	else
		(*print)++;
	return (1);
}
