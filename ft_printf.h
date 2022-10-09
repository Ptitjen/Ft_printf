/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:34:58 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/01 12:35:02 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define HEXMAJ "0123456789ABCDEF"
# define HEXMIN "0123456789abcdef"

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd, int count);
int	ft_putstr_fd(char *s, int fd, int count);
int	ft_putnbr_fd(int n, int fd, int count);
int	ft_put_uhexa(unsigned int nbr, char *base, int count);
int	ft_put_unsigned_nbr(unsigned int n, int fd, int count);
int	ft_pp(unsigned long long int nbr, char *base, int count);

#endif
