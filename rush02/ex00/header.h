/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlimous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:08:23 by chlimous          #+#    #+#             */
/*   Updated: 2023/08/20 23:29:17 by chlimous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strdup(char *src, int size);
char	*ft_strdupright(char *src, int size);
void	ft_convert(char *str, int isfirstcall, char **lines);
int		check_inputisnumber(char *input);
int		ft_verifline(char *str);
int		ft_isprintable(char c);
int		ft_verifdict(char **lines);
char	**ft_dictread(char *dict);
char	**ft_split(char *str, char *charset);
char	*inputisfromdict(char *input, char **lines);
char	*nbfromline(char *str);
char	*resfromline(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*groupname(int size, char **lines);
int		ft_print(char *str, int isfirstcall, char **lines);
int		ft_atoi(char *str);
int		ft_printhundred(char *str, char **lines, int isfirstcall);
int		ft_printten(char *str, char **lines, int isfirstcall);
int		ft_printunit(char *str, char **lines, int isfirstcall);
void	ft_freestrs(char **strs);
int		ft_printsearch(char *str, int isfirstcall, char **lines);
int		ft_printsearchunit(char *str, int isfirstcall, char **lines);
void	ft_printten3(int isfirstcall, char *temp, char *res);
void	ft_printten_print(int isfirstcall, char *res);
char	*ft_printten2(char *temp, char *str, char *res, char **lines);
void	ft_proc(char *temp, char **lines);
void	ft_proc2(char *argv, char **lines);
char	*ft_printten4(char *temp, char **lines);

#endif
