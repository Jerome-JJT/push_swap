/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:22 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/16 10:04:22 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# include "libft.h"
# include "get_next_line.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack {
	int		*n;
	int		len;
	char	id;
}	t_stack;

typedef struct s_dint {
	int	arot;
	int	brot;
}	t_dint;

typedef struct s_iscore {
	int	score;
	int	index;
}	t_iscore;

//main.c
//int		main(int argc, char **argv);
void	ft_simplify_stack(t_stack *a, int *new);
//void	ft_display_stack(t_stack *a, t_stack *b);

//checker.c
void	ft_process_checker(t_stack *a, t_stack *b);
int		ft_switch(t_stack *a, t_stack *b, char *line, int *count);
void	ft_useless_function(t_stack *a, t_stack *b, int *print);

//verify.c
int		ft_verify_stack(t_stack *s);
int		ft_process_input(int argc, char **argv, t_stack *a);
int		ft_store_input(char **args, int start, int len, t_stack *a);

//utils.c
void	ft_putstr(const char *str);
int		ft_isnumber(const char *str);
long	ft_atol(const char *str);
void	ft_write_move(const char *move, const char id);
void	ft_free_2d(char **tab);

//utils2.c
int		ft_abs(int a);
int		ft_smallest_index(t_stack *s);
int		ft_biggest_index(t_stack *s);
int		ft_place_inv(t_stack *s, int search);
void	ft_sort_very_small_stack(t_stack *a, int *print);

//basic_stack.c
t_stack	*ft_new_stack(char id);
void	ft_free_stack(t_stack *s);
int		ft_fill_stack(t_stack *s, int num);
int		ft_push_stack(t_stack *s, int num);
int		ft_pop_stack(t_stack *s);

//advanced_stack.c
t_stack	*ft_copy_stack(t_stack *s);
int		ft_take_stack(t_stack *taker, t_stack *giver, int *print);
int		ft_swap_stack(t_stack *s, int *print);
int		ft_rotate_stack(t_stack *s, int *print);
int		ft_rrotate_stack(t_stack *s, int *print);

//expert_stack.c
int		ft_rotate_all(t_stack *a, t_stack *b, int *print);
int		ft_rrotate_all(t_stack *a, t_stack *b, int *print);
void	ft_rotate_xfor(t_stack *a, t_stack *b, t_dint *rot, int *print);
void	ft_rotate_xfor2(t_stack *a, t_stack *b, t_dint *rot, int *print);
void	ft_rotate_xfor3(t_stack *a, t_stack *b, t_dint *rot, int *print);

//sort_functions.c
void	ft_sort_small_stack(t_stack *a, t_stack *b, int *print);
void	ft_prep_big_stack(t_stack *a, t_stack *b, int tryhard);
void	ft_chunk_stack(t_stack *a, t_stack *b);

//big_sort_functions.c
void	ft_test_stack(t_stack *a, t_stack *b, t_stack *test_stack, int tryhard);
void	ft_test_stack2(t_stack *a, t_stack *b, t_iscore *best, t_dint *move);
void	ft_sort_big_stack(t_stack *a, t_stack *b, int *print);
void	ft_big_stack_choose(t_stack *a, t_stack *b, int *m_nb, int *best_a);
void	ft_big_stack_finish(t_stack *a, t_stack *b, int *print);

#endif
