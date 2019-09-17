/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:18 by scoron            #+#    #+#             */
/*   Updated: 2018/09/09 15:45:41 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_free(int **grid)
{
	int y;

	y = -1;
	while (++y < 9)
	{
		free(grid[y]);
	}
	free(grid);
}

void	ft_print(int **grid, int *pointres)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	if (*pointres != 1)
		ft_error();
	else
		while (j < 9)
		{
			i = 0;
			while (i < 9)
			{
				c = grid[j][i] + '0';
				write(1, &c, 1);
				if (i != 8)
					write(1, " ", 1);
				i++;
			}
			write(1, "\n", 1);
			j++;
		}
}

void	ft_final(int **grid, int **grid_s, int *pointres)
{
	ft_print(grid_s, pointres);
	ft_free(grid);
	ft_free(grid_s);
}
