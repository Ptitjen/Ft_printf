/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:34:41 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/01 16:34:43 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	ft_checklen(unsigned int nb)
{
	unsigned int	len;
	unsigned int	n;

	len = 0;
	n = nb;
	if (nb == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			len ++;
			n = n / 10;
		}
		return (len);
	}
}

static unsigned int	ft_pow(unsigned int len)
{
	unsigned int	i;
	unsigned int	p;

	p = 1;
	i = 1;
	while (i ++ < len)
		p *= 10;
	return (p);
}

int	ft_put_unsigned_nbr(unsigned int n, int fd, int count)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	p;

	i = 0;
	len = ft_checklen(n);
	while (++ i < len)
	{
		p = ft_pow(len - i + 1);
		count = ft_putchar_fd(n / p + '0', fd, count);
		n = n - (p * (n / p));
	}
	count = ft_putchar_fd((n % 10) + '0', fd, count);
	return (count);
}
