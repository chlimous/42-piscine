/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:28:09 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/20 23:16:41 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strdup(char *src, int size)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdupright(char *src, int size)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	dest[size] = '\0';
	i = ft_strlen(src) - 1;
	j = size - 1;
	while (i >= 0 && j >= 0)
	{
		dest[j] = src[i];
		i--;
		j--;
	}
	return (dest);
}
