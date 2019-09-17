/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 11:51:06 by avogt             #+#    #+#             */
/*   Updated: 2018/09/09 15:09:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		**ft_copy_grid(int **grid, int **grid_s)
{
	int line;
	int col;

	line = 0;
	while (line < 9)
	{
		col = 0;
		while (col < 9)
		{
			grid_s[line][col] = grid[line][col];
			col++;
		}
		line++;
	}
	return (grid_s);
}
