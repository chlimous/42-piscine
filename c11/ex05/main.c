/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:25:45 by chlimous          #+#    #+#             */
/*   Updated: 2023/09/06 22:58:25 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	index_op(char *op)
{
	if (*op == '+')
		return (0);
	else if (*op == '-')
		return (1);
	else if (*op == '*')
		return (2);
	else if (*op == '/')
		return (3);
	else if (*op == '%')
		return (4);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	int	(*p[5])(int, int);
	int	indexop;

	p[0] = &ft_add;
	p[1] = &ft_sub;
	p[2] = &ft_multi;
	p[3] = &ft_div;
	p[4] = &ft_mod;
	if (argc == 4)
	{
		indexop = index_op(argv[2]);
		if (indexop == -1)
		{
			ft_putstr("0\n");
		}
		else if (indexop == 3 && ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : division by zero\n");
		else if (indexop == 4 && ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : modulo by zero\n");
		else
		{
			ft_putnbr(p[indexop](ft_atoi(argv[1]), ft_atoi(argv[3])));
			ft_putchar('\n');
		}
	}
}
