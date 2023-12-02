/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   printer2.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/20 22:38:10 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/20 23:29:04 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	ft_printten3(int isfirstcall, char *temp, char *res)
{
	free(temp);
	if (!isfirstcall)
		ft_putchar(' ');
	ft_putstr(res);
	free(res);
}

void	ft_printten_print(int isfirstcall, char *res)
{
	if (!isfirstcall)
		ft_putchar(' ');
	ft_putstr(res);
	free(res);
}

char	*ft_printten2(char *temp, char *str, char *res, char **lines)
{
	temp[0] = str[1];
	temp[1] = str[2];
	temp[2] = '\0';
	res = inputisfromdict(temp, lines);
	return (temp);
}

char	*ft_printten4(char *temp, char **lines)
{
	char	*res;

	temp[1] = '0';
	res = inputisfromdict(temp, lines);
	free(temp);
	return (res);
}
