/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:22 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:22 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_stack(char id)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	s->n = malloc(0);
	s->len = 0;
	s->id = id;
	return (s);
}

void	ft_free_stack(t_stack *s)
{
	free(s->n);
	free(s);
}

int	ft_fill_stack(t_stack *s, int num)
{
	int	*new;
	int	i;

	s->len++;
	new = malloc(sizeof(int) * s->len);
	i = 0;
	while (i < s->len - 1)
	{
		if (s->n[i] == num)
			return (0);
		new[i] = s->n[i];
		i++;
	}
	new[i] = num;
	free(s->n);
	s->n = new;
	return (1);
}

int	ft_push_stack(t_stack *s, int num)
{
	int	*new;
	int	i;

	s->len++;
	new = malloc(sizeof(int) * s->len);
	new[0] = num;
	i = 1;
	while (i < s->len)
	{
		new[i] = s->n[i - 1];
		i++;
	}
	free(s->n);
	s->n = new;
	return (1);
}

int	ft_pop_stack(t_stack *s)
{
	int	*new;
	int	i;
	int	res;

	res = s->n[0];
	s->len--;
	new = malloc(sizeof(int) * s->len);
	i = 0;
	while (i < s->len)
	{
		new[i] = s->n[i + 1];
		i++;
	}
	free(s->n);
	s->n = new;
	return (res);
}
