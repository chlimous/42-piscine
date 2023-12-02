/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/20 04:06:59 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/20 23:15:28 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res);
}

void	ft_freestrs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
