/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:50:45 by fsalomon          #+#    #+#             */
/*   Updated: 2023/12/13 11:43:35 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *argv, ...);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putpointeur(unsigned long long pointeur, char c);
int			ft_put_hexa(unsigned int hexa, char c);
void		ft_putnbr_hexa(unsigned long long n, char c);
int			ft_digits_nb_decimal(long nb);
void		ft_putdigits(int n, char c);
void		ft_putdigits_decimal(int n);
int			ft_putnbr(int n);
int			ft_put_unsigned_nbr(int n);

#endif