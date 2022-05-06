/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:25:52 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/12/10 20:25:52 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -2 equals not sorted list
// -1 equals perfect sorted list
// else, list is sorted but need to rotate
int	ft_verify_stack(t_stack *s)
{
	int	i;
	int	flag;

	if (s->len < 2)
		return (-1);
	flag = -1;
	i = 0;
	while (i < s->len - 1)
	{
		if (s->n[i] > s->n[i + 1])
		{
			if (flag == -1 && s->n[i + 1] < s->n[0])
				flag = i;
			else
				return (-2);
		}
		else if (flag != -1 && s->n[i + 1] > s->n[0])
			return (-2);
		i++;
	}
	return (flag);
}

int	ft_store_input(char **args, int start, int len, t_stack *a)
{
	while (start < len)
	{
		if (!ft_isnumber(args[start]))
		{
			ft_putstr("Error\n");
			ft_free_stack(a);
			return (0);
		}
		if (ft_atol(args[start]) > INT_MAX || ft_atol(args[start]) < INT_MIN
			|| !ft_fill_stack(a, (int)ft_atol(args[start])))
		{
			ft_putstr("Error\n");
			ft_free_stack(a);
			return (0);
		}
		start++;
	}
	return (1);
}

int	ft_process_input(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2 && !ft_isnumber(argv[1]))
	{
		args = ft_split(argv[1], ' ');
		while (args[i] != NULL)
			i++;
		i = ft_store_input(args, 0, i, a);
		ft_free_2d(args);
	}
	else
	{	
		i = ft_store_input(argv, 1, argc, a);
	}
	return (i);
}
