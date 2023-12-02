/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/08 19:30:20 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/08 19:31:14 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	res;

	if (!nb && !power)
		return (1);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = 0;
	res = nb;
	while (i < power - 1)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
