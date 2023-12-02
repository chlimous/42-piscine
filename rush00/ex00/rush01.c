/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: nkuhne <marvin@42.fr>			    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/06 12:41:36 by nkuhne	       #+#    #+#	      */
/*   Updated: 2023/08/06 18:37:57 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int x, int y, int index_x, int index_y)
{
	if (index_y == 0)
	{
		if (index_x == 0)
			ft_putchar('/');
		else if (index_x == x - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else if (index_y == y - 1)
	{
		if (index_x == 0)
			ft_putchar('\\');
		else if (index_x == x - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
	}
	else
	{
		if (index_x == 0 || index_x == x - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{	
	int	index_x;
	int	index_y;

	index_y = 0;
	while (index_y <= y - 1)
	{
		index_x = 0;
		while (index_x <= x - 1)
		{
			print_line(x, y, index_x, index_y);
			index_x++;
		}
		if (x != 0)
			ft_putchar('\n');
		index_y++;
	}
}	
