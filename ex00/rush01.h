/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush01.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:46:08 by yoribeir          #+#    #+#             */
/*   Updated: 2018/09/09 15:26:30 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH01_H
# define FT_RUSH01_H
# include <unistd.h>
# include <stdlib.h>

int		ft_check(int **grid, int line, int col, int nb);
int		**ft_build_grid(char **argv);
int		ft_check_arg(int argc, char **argv);
void	ft_solve(int **grid, int line, int col, int **grid_s);
void	ft_print(int **grid, int *pointres);
void	ft_error();
int		ft_nextline(int line, int col);
int		ft_nextcol(int line, int col);
int		ft_check_built(int **grid);
void	ft_solve_count(int **grid, int line, int col, int *pointres);
int		**ft_copy_grid(int **grid, int **grid_s);
void	ft_final(int **grid, int **grid_s, int *pointres);

#endif
