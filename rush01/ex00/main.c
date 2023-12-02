/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:06:52 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/13 23:21:43 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**ft_input(char *str);
int		ft_is_height_not_there(int **grid, int tab[], int height);
int		ft_is_valid_left(int **grid, int clue, int tab[], int height);
int		ft_is_valid_right(int **grid, int clue, int tab[], int height);
int		ft_is_valid_top(int **grid, int clue, int tab[], int height);
int		ft_is_valid_bottom(int **grid, int clue, int tab[], int height);
int		ft_grid_size(char *str);
void	ft_display(int **grid, int size);
int		**ft_set_start_grid(int **grid, int size);
int		**ft_set_grid(int **grid, int size);

int	*ft_find_empty_cell(int **grid, int size)
{
	int	row;
	int	col;
	int	*res;

	res = (int *)malloc(sizeof(int) * 2);
	if (!res)
		return (0);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0)
			{
				res[0] = row;
				res[1] = col;
				return (res);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_grid_is_complete(int **grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (grid[row][col] == 0)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	ft_comb_is_valid(int **grid, int **clues, int tab[], int height)
{
	if (!ft_is_height_not_there(grid, tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_left(grid, clues[2][tab[0]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_right(grid, clues[3][tab[0]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_top(grid, clues[0][tab[1]], tab, height))
	{
		return (0);
	}
	if (!ft_is_valid_bottom(grid, clues[1][tab[1]], tab, height))
	{
		return (0);
	}
	return (1);
}

int	**ft_solver(int **grid, int **clues, int size)
{
	int	*zero_index;
	int	i;
	int	tab[3];

	if (ft_grid_is_complete(grid, size))
	{
		return (grid);
	}
	zero_index = ft_find_empty_cell(grid, size);
	tab[0] = zero_index[0];
	tab[1] = zero_index[1];
	tab[2] = size;
	i = 1;
	while (i <= size)
	{
		if (ft_comb_is_valid(grid, clues, tab, i))
		{
			grid[zero_index[0]][zero_index[1]] = i;
			if (ft_solver(grid, clues, size))
				return (grid);
			grid[zero_index[0]][zero_index[1]] = 0;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	**grid;
	int	**clues;
	int	size;

	if (argc == 2)
	{
		size = ft_grid_size(argv[1]);
		clues = ft_input(argv[1]);
		grid = 0;
		grid = ft_set_grid(grid, size);
		grid = ft_set_start_grid(grid, size);
		if (clues)
			grid = ft_solver(grid, clues, size);
		if (!grid || !clues)
			write(1, &"Error\n", 6);
		else
			ft_display(grid, size);
	}
	else
		write(1, &"Error\n", 6);
}
