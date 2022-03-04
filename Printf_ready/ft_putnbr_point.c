/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:21:13 by jeulliot          #+#    #+#             */
/*   Updated: 2022/02/01 13:36:52 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	ft_power(unsigned long long int p)
{
	unsigned long long int	i;

	i = 1;
	while (p != 0)
	{
		i = i * 16;
		p = p - 1;
	}
	return (i);
}

static int	ft_power_max(unsigned long long int nbr)
{
	int	p;

	p = 0;
	while (nbr / 16 != 0)
	{
		p ++;
		nbr = nbr / 16;
	}
	return (p);
}

int	ft_pp(unsigned long long int nbr, char *base, int count)
{
	unsigned long long int	j;
	unsigned long long int	d;
	int						p;

	p = ft_power_max (nbr);
	write (1, "0x", 2);
	count = count + 2;
	while (nbr >= 16)
	{
		d = ft_power (p);
		j = base [nbr / d];
		write (1, &j, 1);
		count ++;
		nbr = nbr - d * (nbr / d);
		p = p - 1;
	}
	while (-- p >= 0)
	{
		write (1, &base[0], 1);
		count ++;
	}
	write (1, &base[nbr % 16], 1);
	count ++;
	return (count);
}
