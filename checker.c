/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:25:52 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/12/10 20:25:52 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_new_stack('a');
	if (!ft_process_input(argc, argv, a))
		return (0);
	b = ft_new_stack('b');
	ft_process_checker(a, b);
	if (ft_verify_stack(a) == -1 && b->len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}

void	ft_process_checker(t_stack *a, t_stack *b)
{
	char	*line;
	int		count;

	while (1 == 1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (ft_switch(a, b, line, &count) == 1)
			free(line);
		else
		{
			write(1, "Error\n", 6);
			free(line);
			break ;
		}
	}
}

int	ft_switch(t_stack *a, t_stack *b, char *line, int *count)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_swap_stack(a, count);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_swap_stack(a, count);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_useless_function(a, b, count);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_take_stack(a, b, count);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_take_stack(b, a, count);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_rotate_stack(a, count);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_rotate_stack(b, count);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rotate_all(a, b, count);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rrotate_stack(a, count);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rrotate_stack(b, count);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrotate_all(a, b, count);
	else
		return (0);
	return (1);
}

void	ft_useless_function(t_stack *a, t_stack *b, int *print)
{
	ft_swap_stack(a, print);
	ft_swap_stack(b, print);
}
