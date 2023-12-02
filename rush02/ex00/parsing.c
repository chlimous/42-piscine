/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:20:59 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/03 00:17:43 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isprintable(char c)
{
	if (!(c < 32 || c > 126))
		return (1);
	return (0);
}

int	ft_verifline(char *str)
{
	if (*str >= '0' && *str <= '9')
		while (*str >= '0' && *str <= '9')
			str++;
	else
		return (0);
	if (*str == ' ' || *str == ':')
		while (*str == ' ')
			str++;
	else
		return (0);
	if (*str == ':')
		str++;
	else
		return (0);
	while (*str == ' ')
		str++;
	if (ft_isprintable(*str))
		while (ft_isprintable(*str))
			str++;
	else
		return (0);
	if (*str == '\0')
		return (1);
	else
		return (0);
}

int	ft_verifdict(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
	{
		if (!ft_verifline(lines[count]))
			return (0);
		count++;
	}
	if (count < 41)
		return (0);
	return (1);
}

char	*nbfromline(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	res = ft_strdup(str, i);
	return (res);
}

char	*resfromline(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (*str != ':')
		str++;
	str++;
	while (*str == ' ')
		str++;
	while (str[i])
		i++;
	res = ft_strdup(str, i);
	return (res);
}
