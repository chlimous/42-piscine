/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   combverif.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/13 22:07:36 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/13 23:13:02 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_is_height_not_there(int **grid, int tab[], int height)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (i < tab[2])
	{
		if (grid[i][tab[1]] == height || grid[tab[0]][i] == height)
			c++;
		i++;
	}
	if (c > 0)
		return (0);
	else
		return (1);
}

int	ft_is_valid_left(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = 0;
	while (i <= tab[1])
	{
		if (grid[tab[0]][i] > hightest)
		{
			hightest = grid[tab[0]][i];
			c++;
		}
		i++;
	}
	grid[tab[0]][tab[1]] = 0;
	if ((tab[1] == tab[2] - 1 && c != clue)
		|| (tab[1] != tab[2] - 1 && c > clue))
		return (0);
	else if ((tab[1] == tab[2] - 1 && c == clue)
		|| (tab[1] != tab[2] - 1 && c <= clue))
		return (1);
	return (0);
}

int	ft_is_valid_right(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	if (tab[1] != tab[2] - 1)
		return (1);
	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = tab[2] - 1;
	while (i >= 0)
	{
		if (grid[tab[0]][i] > hightest)
		{
			hightest = grid[tab[0]][i];
			c++;
		}
		i--;
	}
	grid[tab[0]][tab[1]] = 0;
	if (tab[1] == tab[2] - 1 && c != clue)
		return (0);
	else if (tab[1] == tab[2] - 1 && c == clue)
		return (1);
	return (0);
}

int	ft_is_valid_top(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = 0;
	while (i <= tab[0])
	{
		if (grid[i][tab[1]] > hightest)
		{
			hightest = grid[i][tab[1]];
			c++;
		}
		i++;
	}
	grid[tab[0]][tab[1]] = 0;
	if ((tab[0] == tab[2] - 1 && c != clue)
		|| (tab[1] != tab[2] - 1 && c > clue))
		return (0);
	else if ((tab[0] == tab[2] - 1 && c == clue)
		|| (tab[0] != tab[2] - 1 && c <= clue))
		return (1);
	return (0);
}

int	ft_is_valid_bottom(int **grid, int clue, int tab[], int height)
{
	int	c;
	int	hightest;
	int	i;

	if (tab[0] != tab[2] - 1)
		return (1);
	grid[tab[0]][tab[1]] = height;
	hightest = 0;
	c = 0;
	i = tab[2] - 1;
	while (i >= 0)
	{
		if (grid[i][tab[1]] > hightest)
		{
			hightest = grid[i][tab[1]];
			c++;
		}
		i--;
	}
	grid[tab[0]][tab[1]] = 0;
	if (tab[0] == tab[2] - 1 && c != clue)
		return (0);
	else if (tab[0] == tab[2] - 1 && c == clue)
		return (1);
	return (0);
}
