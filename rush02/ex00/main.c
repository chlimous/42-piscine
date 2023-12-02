/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/19 17:57:08 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/20 23:28:20 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "header.h"

void	ft_proc(char *temp, char **lines)
{
	temp = malloc(sizeof(char) * 2);
	temp[0] = '0';
	temp[1] = '\0';
	ft_printunit(temp, lines, 1);
	free(temp);
}

void	ft_proc2(char *argv, char **lines)
{
	ft_convert(argv, 1, lines);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	char	**lines;
	char	*temp;

	temp = 0;
	if (argc == 2 && check_inputisnumber(argv[1]))
		lines = ft_dictread("numbers.dict");
	else if (argc == 3 && check_inputisnumber(argv[1]))
		lines = ft_dictread(argv[2]);
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!ft_verifdict(lines))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	while (*argv[1] == '0')
		argv[1]++;
	if (*argv[1] == '\0')
		ft_proc(temp, lines);
	else
		ft_proc2(argv[1], lines);
	ft_freestrs(lines);
}
