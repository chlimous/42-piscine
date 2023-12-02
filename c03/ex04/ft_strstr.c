/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:26:16 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/02 22:42:00 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	size;

	if (!*to_find)
		return (str);
	size = 0;
	while (to_find[size])
	{
		size++;
	}
	while (*str)
	{
		i = 0;
		while (str[i] == to_find[i])
		{
			if (i == size - 1)
				return (str);
			i++;
		}
		str++;
	}
	return (0);
}
