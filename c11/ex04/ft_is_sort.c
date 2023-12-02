/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/23 20:53:43 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/03 00:11:10 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	is_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_sort_desc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = length - 2;
	while (i >= 0)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (!is_sort_asc(tab, length, (*f)) && !is_sort_desc(tab, length, (*f)))
		return (0);
	return (1);
}
