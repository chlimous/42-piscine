/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:00:53 by chlimous          #+#    #+#             */
/*   Updated: 2023/11/16 20:41:53 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(int *tab, int size)
{
	char	c;
	int		i;

	i = 0;
	while (i < size)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
}

int	ft_is_last_nb(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 9;
	while (i <= size - 1)
	{
		if (tab[size - 1 - i] != j)
			return (0);
		i++;
		j--;
	}
	return (1);
}

int	ft_max_nbr_index(int index, int size)
{
	int	i;
	int	j;

	i = size - 1;
	j = 9;
	while (i > index)
	{
		j--;
		i--;
	}
	return (j);
}

int	*ft_set_nb_tab(int *tab, int size, int index)
{
	tab[index]++;
	while (index < size - 1)
	{
		tab[index + 1] = tab[index] + 1;
		index++;
	}
	return (tab);
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (!ft_is_last_nb(tab, n))
	{
		i = n - 1;
		ft_print_nbr(tab, n);
		write(1, ", ", 2);
		if (tab[i] != ft_max_nbr_index(i, n))
			ft_set_nb_tab(tab, n, i);
		else
		{
			while (tab[i] == ft_max_nbr_index(i, n))
				i--;
			ft_set_nb_tab(tab, n, i);
		}
	}
	ft_print_nbr(tab, n);
}
