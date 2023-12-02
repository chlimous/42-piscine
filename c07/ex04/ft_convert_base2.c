/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/11 00:58:16 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/11 02:12:17 by chlimous         ###   ########.fr       */
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
