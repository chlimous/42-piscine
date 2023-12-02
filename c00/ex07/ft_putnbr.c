/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:32:56 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/02 18:10:21 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nblong;

	nblong = nb;
	if (nblong < 0)
	{
		ft_putchar('-');
		nblong = -nblong;
	}
	if (nblong / 10 != 0)
	{
		ft_putnbr(nblong / 10);
	}
	ft_putchar(nblong % 10 + 48);
}
