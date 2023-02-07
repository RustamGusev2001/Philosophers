/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:31:13 by kcrius            #+#    #+#             */
/*   Updated: 2022/07/05 20:31:15 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	n_len(int n, int *len)
{
	*len = 0;
	while (n)
	{
		++(*len);
		n /= 10;
	}
}

static void	fill_res(int n, char *res, int len, int minus)
{
	int	i;

	i = len - 1;
	if (minus < 0)
		res[0] = '-';
	if (n == -2147483648)
	{
		res[i] = '8';
		--i;
		n /= -10;
	}
	while (n > 0)
	{
		res[i] = n % 10 + '0';
		--i;
		n /= 10;
	}
	res[len] = '\0';
}

static char	*get_zero(void)
{
	char	*res;

	res = (char *)malloc(2);
	if (!res)
		return (0);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*res;

	minus = 1;
	if (n < 0)
	{
		n *= -1;
		minus = -1;
	}
	if (n == 0)
		return (get_zero());
	n_len(n, &len);
	if (minus < 0)
		++len;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	fill_res(n, res, len, minus);
	return (res);
}
