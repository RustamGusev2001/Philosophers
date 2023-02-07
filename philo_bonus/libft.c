/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:30:54 by kcrius            #+#    #+#             */
/*   Updated: 2022/07/05 20:30:56 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		++i;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int	error(char *s)
{
	if (!s)
		return (-2);
	write(1, s, ft_strlen(s));
	return (-1);
}

void	print_unsigned_number(unsigned long int num, int base, char x)
{
	char	c;

	if (num >= (unsigned long)base)
		print_unsigned_number(num / base, base, x);
	c = num % base;
	if (c > 9)
		c = c - 10 + x;
	else
		c = c + '0';
	write(1, &c, 1);
}
