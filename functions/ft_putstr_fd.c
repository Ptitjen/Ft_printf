/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:19:24 by jeulliot          #+#    #+#             */
/*   Updated: 2022/02/22 15:23:33 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd, int count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (count + 6);
	}
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		count ++;
		i ++;
	}
	return (count);
}
