/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:25:26 by scoron            #+#    #+#             */
/*   Updated: 2018/09/09 16:11:36 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_nextline(int line, int col)
{
	if (line < 8 && col == 8)
		line = line + 1;
	return (line);
}

int		ft_nextcol(int line, int col)
{
	if (col < 8)
		col = col + 1;
	else if (line < 8)
		col = 0;
	return (col);
}

void	ft_calculate_result(int line, int col, int *pointres)
{
	if (*pointres > 1)
		return ;
	else if (line == 8 && col == 8)
		*pointres += 1;
	else
		return ;
}

void	ft_solve_count(int **grid, int line, int col, int *pointres)
{
	int nb;

	if (*pointres > 1)
		return ;
	if (grid[line][col] != 0)
	{
		if (line < 8 || col < 8)
			ft_solve_count(grid, ft_nextline(line, col),
					ft_nextcol(line, col), pointres);
		ft_calculate_result(line, col, pointres);
		return ;
	}
	nb = 0;
	while (++nb < 10)
	{
		if (ft_check(grid, line, col, nb))
		{
			grid[line][col] = nb;
			if (line < 8 || col < 8)
				ft_solve_count(grid, ft_nextline(line, col),
						ft_nextcol(line, col), pointres);
			ft_calculate_result(line, col, pointres);
		}
	}
	grid[line][col] = 0;
}
