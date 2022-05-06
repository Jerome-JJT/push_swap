/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:22 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:22 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*new;

	a = ft_new_stack('a');
	if (!ft_process_input(argc, argv, a))
		return (0);
	b = ft_new_stack('b');
	new = malloc(sizeof(int) * a->len);
	ft_simplify_stack(a, new);
	free (a->n);
	a->n = new;
	if (ft_verify_stack(a) != -1 && a->len > 100)
		ft_prep_big_stack(a, b, 30);
	else if (ft_verify_stack(a) != -1 && a->len > 5)
		ft_prep_big_stack(a, b, 1);
	else if (ft_verify_stack(a) != -1 && a->len > 3)
		ft_sort_small_stack(a, b, NULL);
	else if (ft_verify_stack(a) != -1)
		ft_sort_very_small_stack(a, NULL);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}

/*
void	ft_display_stack(t_stack *a, t_stack *b)
{
	int	i;

	printf("A\n");
	i = 0;
	while (i < a->len)
	{
		printf("%d\n", a->n[i]);
		i++;
	}
	printf("\nB\n");
	i = 0;
	while (i < b->len)
	{
		printf("%d\n", b->n[i]);
		i++;
	}
	printf("\n");
}
*/

void	ft_simplify_stack(t_stack *a, int *new)
{
	int	i;
	int	smallest;

	i = 0;
	while (i < a->len)
	{
		new[i] = -1;
		i++;
	}
	i = 0;
	while (i < a->len - 1)
	{
		smallest = ft_smallest_index(a);
		new[smallest] = i;
		a->n[smallest] = INT_MAX;
		i++;
	}
	i = 0;
	while (i < a->len)
	{
		if (new[i] == -1)
			new[i] = a->len - 1;
		i++;
	}
}
