/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/11 00:41:10 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/02 23:27:17 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_verif_base(char *base);

char	*ft_set_nbr_start(char *nbr, int *min)
{
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	*min = 0;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			*min = 1 - *min;
		nbr++;
	}
	return (nbr);
}

long	ft_atoi_base(char *str, char *base)
{
	long	res;
	int		index_base;
	int		i;

	res = 0;
	index_base = 0;
	while (*str && index_base >= 0)
	{
		index_base = -1;
		i = 0;
		while (base[i] && index_base < 0)
		{
			if (base[i] == *str)
				index_base = i;
			i++;
		}
		if (index_base >= 0)
			res = res * ft_strlen(base) + index_base;
		str++;
	}
	return (res);
}

int	ft_len_nb(int nbr, char *base)
{
	int	i;

	i = 1;
	while (nbr / ft_strlen(base) != 0)
	{
		i++;
		nbr = nbr / ft_strlen(base);
	}
	return (i);
}

void	ft_nb_to_base(long nb, char *base, int index, char *nbr_dest)
{
	if (nb / ft_strlen(base) != 0)
		ft_nb_to_base(nb / ft_strlen(base), base, index - 1, nbr_dest);
	nbr_dest[index] = base[nb % ft_strlen(base)];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long		nb_dec;
	char		*nb_dest;
	int			min;

	if (ft_verif_base(base_from) && ft_verif_base(base_to))
	{
		min = 0;
		nbr = ft_set_nbr_start(nbr, &min);
		nb_dec = ft_atoi_base(nbr, base_from);
		nb_dest = malloc(sizeof(char) * ft_len_nb(nb_dec, base_to) + min + 1);
		if (!nb_dest)
			return (NULL);
		if (min)
		{
			*nb_dest = '-';
			nb_dest++;
		}
		ft_nb_to_base(nb_dec, base_to, ft_len_nb(nb_dec, base_to) - 1, nb_dest);
		if (*nb_dest == base_to[0])
			return (nb_dest);
		else
			return (nb_dest - min);
	}
	return (0);
}
