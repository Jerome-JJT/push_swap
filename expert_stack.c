/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:21 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:21 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_all(t_stack *a, t_stack *b, int *print)
{
	int	i;
	int	temp;

	if (a->len < 2)
		return (1);
	i = -1;
	temp = a->n[0];
	while (++i < a->len - 1)
		a->n[i] = a->n[i + 1];
	a->n[a->len - 1] = temp;
	if (b->len < 2)
		return (1);
	i = -1;
	temp = b->n[0];
	while (++i < b->len - 1)
		b->n[i] = b->n[i + 1];
	b->n[b->len - 1] = temp;
	if (print == NULL)
		write(1, "rr\n", 3);
	else
		(*print)++;
	return (1);
}

int	ft_rrotate_all(t_stack *a, t_stack *b, int *print)
{
	int	i;
	int	temp;

	if (a->len < 2)
		return (1);
	i = a->len;
	temp = a->n[a->len - 1];
	while (--i > 0)
		a->n[i] = a->n[i - 1];
	a->n[0] = temp;
	if (b->len < 2)
		return (1);
	i = b->len;
	temp = b->n[b->len - 1];
	while (--i > 0)
		b->n[i] = b->n[i - 1];
	b->n[0] = temp;
	if (print == NULL)
		write(1, "rrr\n", 4);
	else
		(*print)++;
	return (1);
}

void	ft_rotate_xfor(t_stack *a, t_stack *b, t_dint *rot, int *print)
{
	while (rot->arot != 0 || rot->brot != 0)
	{
		if (rot->arot < 0 && rot->brot > 0 && ft_abs(rot->brot) > a->len)
		{
			ft_rotate_all(a, b, print);
			rot->arot = (rot->arot - 1) % a->len;
			rot->brot--;
		}
		if (rot->arot > 0 && rot->brot < 0 && ft_abs(rot->brot) > a->len)
		{
			ft_rrotate_all(a, b, print);
			rot->arot = (rot->arot + 1) % a->len;
			rot->brot++;
		}
		if (rot->arot < 0 && rot->brot > 0 && ft_abs(rot->arot) > b->len)
		{
			ft_rrotate_all(a, b, print);
			rot->arot++;
			rot->brot = (rot->brot + 1) % b->len;
		}
		ft_rotate_xfor2(a, b, rot, print);
	}
}

void	ft_rotate_xfor2(t_stack *a, t_stack *b, t_dint *rot, int *print)
{
	if (rot->arot > 0 && rot->brot < 0 && ft_abs(rot->arot) > b->len)
	{
		ft_rotate_all(a, b, print);
		rot->arot--;
		rot->brot = (rot->brot - 1) % b->len ;
	}
	if (rot->arot > 0 && rot->brot > 0)
	{
		ft_rotate_all(a, b, print);
		rot->arot--;
		rot->brot--;
	}
	else if (rot->arot < 0 && rot->brot < 0)
	{
		ft_rrotate_all(a, b, print);
		rot->arot++;
		rot->brot++;
	}
	else
		ft_rotate_xfor3(a, b, rot, print);
}

void	ft_rotate_xfor3(t_stack *a, t_stack *b, t_dint *rot, int *print)
{
	if (rot->arot > 0)
	{
		ft_rotate_stack(a, print);
		rot->arot--;
	}
	else if (rot->arot < 0)
	{
		ft_rrotate_stack(a, print);
		rot->arot++;
	}
	else if (rot->brot > 0)
	{
		ft_rotate_stack(b, print);
		rot->brot--;
	}
	else if (rot->brot < 0)
	{
		ft_rrotate_stack(b, print);
		rot->brot++;
	}
}
