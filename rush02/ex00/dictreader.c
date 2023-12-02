/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictreader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:53:49 by daeunki2          #+#    #+#             */
/*   Updated: 2023/08/20 23:17:00 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_dictread(char *dict)
{
	int		fd;
	int		n;
	int		i;
	char	buf[10000];

	i = 0;
	fd = open(dict, O_RDONLY);
	n = read(fd, buf, 10000);
	close(fd);
	return (ft_split(buf, "\n"));
}
