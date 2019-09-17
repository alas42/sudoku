/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:25:04 by yoribeir          #+#    #+#             */
/*   Updated: 2018/09/09 20:02:42 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int		**ft_malloc(int **grid)
{
	int col;

	if (!(grid = malloc(sizeof(int *) * 9)))
		return (NULL);
	col = -1;
	while (++col < 9)
	{
		if (!(grid[col] = malloc(sizeof(int) * 9)))
			return (NULL);
	}
	return (grid);
}

int		main(int argc, char **argv)
{
	int		**grid;
	int		**grid_s;
	int		*pointres;
	int		res;

	res = 0;
	pointres = &res;
	grid_s = NULL;
	if (!(ft_check_arg(argc, argv)))
	{
		ft_error();
		return (0);
	}
	grid = ft_build_grid(argv);
	if (!(ft_check_built(grid)))
	{
		ft_error();
		return (0);
	}
	grid_s = ft_malloc(grid_s);
	ft_solve_count(grid, 0, 0, pointres);
	if (*pointres == 1)
		ft_solve(grid, 0, 0, grid_s);
	ft_final(grid, grid_s, pointres);
	return (0);
}
