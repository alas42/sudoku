/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:21:21 by yoribeir          #+#    #+#             */
/*   Updated: 2018/12/10 16:43:18 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_check_built(int **grid)
{
	int y;
	int i;

	y = 0;
	while (y < 9)
	{
		i = 0;
		while (i < 9)
		{
			if (grid[y][i] != 0)
			{
				if (!(ft_check(grid, y, i, grid[y][i])))
					return (0);
			}
			i++;
		}
		y++;
	}
	return (1);
}

int		ft_check(int **grid, int line, int col, int nb)
{
	int i;
	int colstart;
	int linestart;

	colstart = col / 3 * 3;
	linestart = line / 3 * 3;
	i = 0;
	while (i < 9)
	{
		if (grid[line][i] == nb && i != col)
			return (0);
		if (grid[i][col] == nb && i != line)
			return (0);
		if (grid[linestart + (i / 3)][colstart + (i % 3)] == nb &&
				(linestart + (i / 3) != line || colstart + (i % 3) != col))
			return (0);
		i++;
	}
	return (1);
}
