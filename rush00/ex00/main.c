/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:35:20 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/06 18:59:19 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (sign == -1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	if (!(*str >= '0' && *str <= '9') && *str)
		return (0);
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
}
