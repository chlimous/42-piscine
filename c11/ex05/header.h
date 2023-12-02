/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:57:56 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/24 04:45:53 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

int		index_op(char *op);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_add(int nb1, int nb2);
int		ft_sub(int nb1, int nb2);
int		ft_multi(int nb1, int nb2);
int		ft_div(int nb1, int nb2);
int		ft_mod(int nb1, int nb2);
void	ft_putnbr(int nb);

#endif
