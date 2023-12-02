/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/10 17:23:34 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/10 18:15:34 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
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

char	**ft_sort_tabstr(char **tabstr, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strcmp(tabstr[j], tabstr[j + 1]) > 0)
			{
				temp = tabstr[j];
				tabstr[j] = tabstr[j + 1];
				tabstr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (tabstr);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		argv++;
		ft_sort_tabstr(argv, argc - 1);
		while (i < argc - 1)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
}
