/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/04 12:21:00 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/12/02 20:17:32 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

int	ft_char_upper(char *str)
{
	return (*str >= 'A' && *str <= 'Z');
}

int	ft_char_lower(char *str)
{
	return (*str >= 'a' && *str <= 'z');
}

int	ft_char_numeric(char *str)
{
	return (*str >= '0' && *str <= '9');
}

int	ft_char_alphanumeric(char *str)
{
	return (ft_char_upper(str) || ft_char_lower(str) || ft_char_numeric(str));
}

char	*ft_strcapitalize(char *str)
{
	char	*src;

	src = str;
	while (*str)
	{
		if (ft_char_alphanumeric(str))
		{
			if (ft_char_lower(str))
			{
				*str -= 32;
			}
			str++;
			while (ft_char_alphanumeric(str))
			{
				if (ft_char_upper(str))
				{
					*str += 32;
				}
				str++;
			}
		}
		str++;
	}
	return (src);
}
