/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:08:27 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/13 22:40:40 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_grid_size(char *str)
{
	int	i;

	i = 4;
	while (i <= 6)
	{
		if (ft_strlen(str) == (i * 4 * 2 - 1))
			return (i);
		i++;
	}
	return (0);
}

int	**ft_alloc_clues(int **clues, int size)
{
	int	i;

	clues = (int **)malloc(sizeof(int *) * 4);
	if (!clues)
		return (0);
	i = 0;
	while (i < 4)
	{
		clues[i] = (int *)malloc(sizeof(int) * size);
		if (!clues[i])
			return (0);
		i++;
	}
	return (clues);
}

int	**ft_set_clues(char *str, int **clues, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		else
		{
			clues[(i - j) / size][(i - j) % size] = str[i] - 48;
			i++;
			if (str[i] != ' ' && str[i] != '\0')
				return (0);
			else
			{
				if (str[i])
					i++;
				j++;
			}
		}
	}
	return (clues);
}

int	**ft_input(char *str)
{
	int	**clues;
	int	size;

	size = ft_grid_size(str);
	clues = 0;
	if (size)
	{
		clues = ft_alloc_clues(clues, size);
		clues = ft_set_clues(str, clues, size);
		return (clues);
	}
	else
		return (0);
}
