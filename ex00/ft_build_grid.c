/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:21:32 by avogt             #+#    #+#             */
/*   Updated: 2018/09/09 20:02:48 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_check_arg(int argc, char **argv)
{
	int line;
	int col;

	line = 1;
	if (argc != 10)
		return (0);
	else
	{
		while (line <= 9)
		{
			col = 0;
			while (col < 9)
			{
				if (argv[line][col] != '.'
						&& !(argv[line][col] >= '1' && argv[line][col] <= '9'))
					return (0);
				col++;
			}
			line++;
		}
	}
	return (1);
}

int		**ft_build_grid(char **argv)
{
	int line;
	int col;
	int **grid;

	if (!(grid = malloc(sizeof(int *) * 9)))
		return (0);
	col = -1;
	while (++col < 9)
	{
		if (!(grid[col] = malloc(sizeof(int) * 9)))
			return (0);
	}
	line = 0;
	while (++line <= 9)
	{
		col = -1;
		while (++col < 9)
		{
			if (argv[line][col] == '.')
				grid[line - 1][col] = 0;
			else
				grid[line - 1][col] = argv[line][col] - '0';
		}
	}
	return (grid);
}
