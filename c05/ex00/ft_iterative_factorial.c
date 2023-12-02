/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:31:47 by chlimous          #+#    #+#             */
/*   Updated: 2023/12/02 22:50:13 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	i = nb - 1;
	res = nb;
	while (i >= 1)
	{
		res = res * i;
		i--;
	}
	return (res);
}
