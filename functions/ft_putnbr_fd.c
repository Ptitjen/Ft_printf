/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:39:14 by jeulliot          #+#    #+#             */
/*   Updated: 2022/02/22 16:00:39 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	ft_checklen(int nb)
{
	int	len;
	int	n;

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

static int	ft_pow(int len)
{
	int	i;
	int	p;

	p = 1;
	i = 1;
	while (i ++ < len)
		p *= 10;
	return (p);
}

int	ft_putnbr_fd(int n, int fd, int count)
{
	int	len;
	int	i;
	int	p;

	i = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return (count + 11);
	}
	len = ft_checklen(n);
	if (n < 0)
	{
		i ++;
		len ++;
		count = ft_putchar_fd('-', fd, count);
		n = -n;
	}
	while (++ i < len)
	{
		p = ft_pow(len - i + 1);
		count = ft_putchar_fd(n / p + '0', fd, count);
		n = n - (p * (n / p));
	}
	return (ft_putchar_fd((n % 10) + '0', fd, count));
}
