/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:51:00 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/02 20:18:31 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_hex(unsigned char c)
{
	char	*base;
	int		res;

	base = "0123456789abcdef";
	res = c / 16;
	ft_putchar(base[res]);
	res = c % 16;
	ft_putchar(base[res]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			ft_putchar('\\');
			ft_putchar_hex(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
