/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:35:21 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/01 12:35:23 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_check_char_print(int ct, va_list t, char *c)
{
	if (*c == 'c')
		ct = ft_putchar_fd(va_arg(t, int), 1, ct);
	if (*c == 'd' || *c == 'i')
		ct = ft_putnbr_fd(va_arg(t, int), 1, ct);
	if (*c == 's')
		ct = ft_putstr_fd(va_arg(t, char *), 1, ct);
	if (*c == 'p')
		ct = ft_pp(va_arg(t, unsigned long long int), HEXMIN, ct);
	if (*c == 'u')
		ct = ft_put_unsigned_nbr(va_arg(t, unsigned int), 1, ct);
	if (*c == 'x')
		ct = ft_put_uhexa(va_arg(t, unsigned int), HEXMIN, ct);
	if (*c == 'X')
		ct = ft_put_uhexa(va_arg(t, unsigned int), HEXMAJ, ct);
	if (*c == '%')
		ct = ft_putchar_fd('%', 1, ct);
	return (ct);
}

int	ft_printf(const char *str, ...)
{
	va_list	t;
	char	*c;
	int		count;

	va_start(t, str);
	c = (char *)str;
	count = 0;
	while (*c)
	{
		if (*c != '%')
			count = ft_putchar_fd(*c, 1, count);
		else
			count = ft_check_char_print(count, t, ++ c);
		c ++;
	}
	va_end(t);
	return (count);
}
