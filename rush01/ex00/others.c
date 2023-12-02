/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:08:39 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/13 22:19:36 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_grid_size(char *str);

int	**ft_set_start_grid(int **grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	return (grid);
}

int	**ft_set_grid(int **grid, int size)
{
	int	row;

	grid = (int **)malloc(sizeof(int *) * size);
	if (!grid)
		return (0);
	row = 0;
	while (row < size)
	{
		grid[row] = (int *)malloc(sizeof(int) * size);
		if (!grid[row])
			return (0);
		row++;
	}
	return (grid);
}
