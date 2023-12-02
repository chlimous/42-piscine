/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/05 11:14:55 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/06 18:37:20 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int x, int y, int x_index, int y_index)
{
	if (y_index == 0 || y_index == y - 1)
	{
		if (x_index == 0 || x_index == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (x_index == 0 || x_index == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	x_index;
	int	y_index;

	y_index = 0;
	while (y_index < y)
	{
		x_index = 0;
		while (x_index < x)
		{
			print_line(x, y, x_index, y_index);
			x_index++;
		}
		if (x != 0)
			write(1, "\n", 1);
		y_index++;
	}
}
