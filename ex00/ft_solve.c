/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:25:26 by scoron            #+#    #+#             */
/*   Updated: 2018/12/12 17:13:17 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_solve(int **grid, int line, int col, int **grid_s)
{
	int nb;

	if (grid[line][col] != 0)
	{
		if (line < 8 || col < 8)
			ft_solve(grid, ft_nextline(line, col),
					ft_nextcol(line, col), grid_s);
		else
			grid_s = ft_copy_grid(grid, grid_s);
		return ;
	}
	nb = 0;
	while (++nb < 10)
	{
		if (ft_check(grid, line, col, nb))
		{
			grid[line][col] = nb;
			if (line < 8 || col < 8)
				ft_solve(grid, ft_nextline(line, col),
						ft_nextcol(line, col), grid_s);
			else
				grid_s = ft_copy_grid(grid, grid_s);
		}
	}
	grid[line][col] = 0;
}