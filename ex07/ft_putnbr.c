/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:42:30 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/03 20:06:54 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	buf[10];
	int		i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	while (nb != 0)
	{
		buf[i++] = '0' + nb % 10;
		nb /= 10;
	}
	while (i >= 0)
	{
		ft_putchar(buf[i--]);
	}
}
