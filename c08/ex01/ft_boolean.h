/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: chlimous <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/08/17 15:34:27 by chlimous	       #+#    #+#	      */
/*   Updated: 2023/08/17 16:01:34 by chlimous         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define EVEN(NBR) ((NBR % 2 == 0) ? 1 : 0)
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0

typedef int	t_bool;

#endif
