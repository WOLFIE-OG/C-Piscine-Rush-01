/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:11:02 by otodd             #+#    #+#             */
/*   Updated: 2023/10/15 13:33:15 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "funcs/funcs.h"

int	parse_args(char *arg_a, int *clue_array)
{
	int	index;

	index = 0;
	while (*arg_a)
	{
		if (*arg_a != ' ')
		{
			if ((*arg_a >= 'a' && *arg_a <= 'z')
				|| (*arg_a >= 'A' && *arg_a <= 'Z'))
				return (0);
			if (ft_is_valid_num(*arg_a) != 1)
				return (0);
			clue_array[index] = *arg_a - '0';
			index++;
		}
		arg_a++;
	}
	return (1);
}

int	**make_board(int x, int y)
{
	int		**board;
	int		i;

	i = 0;
	board = malloc(sizeof(int *) * y);
	while (i <= y)
	{
		board[i] = malloc(x * sizeof(int));
		i++;
	}
	return (board);
}

void	sub_main(int **board, int x, int y, int *clue_array)
{
	int	x_index;
	int	y_index;
	int	clue_offset;

	clue_offset = 0;
	x_index = 0;
	y_index = 0;
	while (y_index < y)
	{
		while (x_index < x)
		{
			board[y_index][x_index] = clue_array[clue_offset];
			ft_putchar(board[y_index][x_index] + '0');
			ft_putchar(' ');
			x_index++;
			clue_offset++;
		}
		ft_putchar('\n');
		x_index = 0;
		y_index++;
	}
}

int	main(int arg_n, char **arg_a)
{
	int	clue_array[15];
	int	**board;
	int	x;
	int	y;

	x = 4;
	y = x;
	board = make_board(x, y);
	if (arg_n == 1)
		return (0);
	if (arg_n > 2)
		return (0);
	if (ft_strlen(arg_a[1]) == 31)
	{
		if (parse_args(arg_a[1], clue_array))
		{
			sub_main(board, x, y, clue_array);
		}
	}
	return (0);
}
