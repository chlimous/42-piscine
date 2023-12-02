/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:07:56 by daeunki2          #+#    #+#             */
/*   Updated: 2023/08/20 20:49:25 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_inputisnumber(char *input)
{
	int	i;

	if (!*input || ft_strlen(input) > 39)
		return (0);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*inputisfromdict(char *input, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (ft_strcmp(input, nbfromline(lines[i])) == 0)
			return (resfromline(lines[i]));
		i++;
	}
	return (0);
}
