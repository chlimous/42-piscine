/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/07 21:56:07 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/02 22:43:39 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	ft_verif_base(char *base)
{
	if (ft_strlen(base) <= 1)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		if (ft_count_char(base, *base) > 1)
			return (0);
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	if (ft_verif_base(base))
	{
		nb = nbr;
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb / ft_strlen(base) != 0)
			ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
}
