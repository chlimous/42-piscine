/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:14:29 by chlimous          #+#    #+#             */
/*   Updated: 2023/11/16 20:41:39 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printnbr(int n)
{
	if (n < 10)
	{
		ft_putchar('0');
		ft_putchar(n + 48);
	}
	else
	{
		ft_putchar(n / 10 + 48);
		ft_putchar(n % 10 + 48);
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_printnbr(x);
			ft_putchar(' ');
			ft_printnbr(y);
			if (!(x == 98 && y == 99))
				write(1, ", ", 2);
			y++;
		}
		x++;
	}
}
