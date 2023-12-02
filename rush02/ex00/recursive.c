/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/19 19:54:59 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/20 23:33:23 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

int	ft_nbsize(char *str)
{
	int	i;

	while (*str && *str == '0')
		str++;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print(char *str, int isfirstcall, char **lines)
{
	char	*temp;

	temp = inputisfromdict(str, lines);
	if (temp && *str != '0')
	{
		if (!isfirstcall)
			ft_putchar(' ');
		ft_putstr(temp);
		free(temp);
		return (1);
	}
	else
	{
		free(temp);
		ft_printsearch(str, isfirstcall, lines);
	}
	return (1);
}

char	*groupname(int size, char **lines)
{
	char	*temp;
	char	*res;

	temp = malloc(sizeof(char) * (size + 1 + 1));
	if (!temp)
		return (0);
	temp[size + 1] = '\0';
	temp[0] = '1';
	while (size > 0)
	{
		temp[size] = '0';
		size--;
	}
	res = inputisfromdict(temp, lines);
	free(temp);
	return (res);
}

int	is_group_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 3)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_convert(char *str, int isfirstcall, char **lines)
{
	char	*strdup;
	char	*strdupright;
	char	*grpname;
	int		strdupsize;

	strdupsize = ft_strlen(str) % 3;
	if (!strdupsize)
		strdupsize = 3;
	strdup = ft_strdup(str, strdupsize);
	ft_print(strdup, isfirstcall, lines);
	if ((ft_strlen(str) - 1) / 3 != 0)
	{
		if (!is_group_empty(strdup))
		{
			ft_putchar(' ');
			grpname = groupname((ft_strlen(str) - 1) / 3 * 3, lines);
			ft_putstr(grpname);
			free(grpname);
		}
		strdupright = ft_strdupright(str, (ft_strlen(str) - 1) / 3 * 3);
		ft_convert(strdupright, 0, lines);
		free(strdupright);
	}
	free(strdup);
}
