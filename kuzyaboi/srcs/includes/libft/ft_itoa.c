/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:46:36 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/26 15:51:41 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter_int_of_n(int nbr)
{
	int counter;

	counter = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		counter++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		counter++;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		index;
	int		counter;

	index = 0;
	counter = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(ft_counter_int_of_n(n))))
		return (0);
	counter = ft_counter_int_of_n(n) - 1;
	if (n < 0)
	{
		str[index] = '-';
		n *= -1;
		index++;
	}
	while (counter >= index)
	{
		str[counter] = (n % 10) + '0';
		n /= 10;
		counter--;
	}
	return (str);
}
