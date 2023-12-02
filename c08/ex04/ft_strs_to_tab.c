/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/17 15:40:11 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/17 20:42:29 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tstr;
	int			i;

	tstr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tstr)
		return (0);
	i = 0;
	while (i < ac)
	{
		tstr[i].size = ft_strlen(av[i]);
		tstr[i].str = av[i];
		tstr[i].copy = ft_strdup(av[i]);
		i++;
	}
	tstr[i].str = 0;
	return (tstr);
}
