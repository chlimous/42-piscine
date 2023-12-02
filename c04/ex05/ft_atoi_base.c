/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/08 20:30:04 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/02 22:43:54 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_index_base(char *base, char c)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;
	int	count;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		count = 0;
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;

	if (ft_verif_base(base))
	{
		res = 0;
		sign = 1;
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -sign;
			str++;
		}
		while (ft_index_base(base, *str) >= 0)
		{
			res = res * ft_strlen(base) + ft_index_base(base, *str);
			str++;
		}
		return (res * sign);
	}
	return (0);
}
