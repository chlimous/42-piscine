/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/20 18:40:24 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/03 00:17:30 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

int	ft_printhundred(char *str, char **lines, int isfirstcall)
{
	char	*temp;
	char	*res;

	temp = malloc(sizeof(char) * 2);
	if (!temp)
		return (0);
	temp[0] = str[0];
	temp[1] = '\0';
	if (ft_printunit(temp, lines, isfirstcall))
	{
		isfirstcall = 0;
		res = groupname(2, lines);
		if (res)
		{
			if (!isfirstcall)
				ft_putchar(' ');
			ft_putstr(res);
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

int	ft_printten(char *str, char **lines, int isfirstcall)
{
	char	*temp;
	char	*res;

	res = 0;
	temp = malloc(sizeof(char) * 3);
	if (!temp)
		return (0);
	temp = ft_printten2(temp, str, res, lines);
	res = inputisfromdict(temp, lines);
	if (res)
	{
		ft_printten3(isfirstcall, temp, res);
		return (2);
	}
	else
	{
		res = ft_printten4(temp, lines);
		if (res)
		{
			ft_printten_print(isfirstcall, res);
			return (1);
		}
		free(res);
	}
	return (0);
}

int	ft_printunit(char *str, char **lines, int isfirstcall)
{
	char	*temp;

	temp = inputisfromdict(str, lines);
	if (temp)
	{
		if (!isfirstcall)
			ft_putchar(' ');
		ft_putstr(temp);
		free(temp);
		return (1);
	}
	return (0);
}

int	ft_printsearch(char *str, int isfirstcall, char **lines)
{
	int		res;

	res = 0;
	if (ft_atoi(str) > 99)
	{
		res = ft_printhundred(str, lines, isfirstcall);
		if (!res)
			return (0);
		isfirstcall = 0;
	}
	if (ft_atoi(str) % 100 > 9)
	{
		res = ft_printten(str, lines, isfirstcall);
		if (!res)
			return (0);
		isfirstcall = 0;
	}
	if (ft_atoi(str) % 10 > 0 && res != 2)
		ft_printsearchunit(str, isfirstcall, lines);
	return (1);
}

int	ft_printsearchunit(char *str, int isfirstcall, char **lines)
{
	char	*temp;
	int		res;

	temp = malloc(sizeof(char) * 2);
	temp[0] = str[2];
	temp[1] = '\0';
	res = ft_printunit(temp, lines, isfirstcall);
	free(temp);
	if (!res)
		return (0);
	return (1);
}
