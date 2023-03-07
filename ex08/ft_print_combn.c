/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:10:27 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/03/06 22:06:21 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	all_digits_different(int num)
{
	int	i;
	bool	digits_seen[10];

	i = 0;
	while (i++ < 10)
		digits_seen[i] = false;

	while (num != 0)
	{
		i = num % 10;
		if (digits_seen[i])
			return (false);
		digits_seen[i] = true;
		num /= 10;
	}

	return (true);
}

void	print_comb(int num)
{
	int	i;
	char*	digits[9];

	i = 0;
	while (num != 0)
	{
		digits[i] = num % 10;
		num /= 10;
		i++;
	}
	while (i >= 0)
	{
		ft_putchar(digits[i]);
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		max_value;

	i = 0;
	max_value = 0;
	while (i < n)
	{
		max_value *= 10;
		max_value += 9 - i;
		i++;
	}
	i = 0;
	while(i <= max_value)
	{
		if(all_digits_different(i))
		{
			print_comb(i);
			if (i != max_value)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		i++;
	}
}

int main()
{
	ft_print_combn(3);
}
