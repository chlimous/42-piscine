/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:36:38 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/02 23:17:53 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_valid(char *grid, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (grid[i] == row + 48)
			return (0);
		if (grid[i] - 48 - i == row - col || grid[i] - 48 + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	ft_printres(char *grid)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(grid[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_solve(char *grid, int col, int nb_res)
{
	int	row;

	if (col == 10)
	{
		nb_res++;
		ft_printres(grid);
	}
	else
	{
		row = 0;
		while (row < 10)
		{
			if (ft_is_valid(grid, row, col))
			{
				grid[col] = row + 48;
				nb_res = ft_solve(grid, col + 1, nb_res);
			}
			row++;
		}
	}
	return (nb_res);
}

int	ft_ten_queens_puzzle(void)
{
	char	grid[10];

	return (ft_solve(grid, 0, 0));
}
