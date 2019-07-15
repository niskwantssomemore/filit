/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:32:14 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 19:05:31 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(const char *str, int i, int sign)
{
	if (str[i] == '-')
		sign *= -1;
	return (sign);
}

int			ft_atoi(const char *str)
{
	int					i;
	long int			nbr;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
				|| str[i] == '\f' || str[i] == '\v' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_sign(str, i, sign);
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (nbr > 922337203685477587 && sign == 1)
			return (-1);
		if (nbr < -922337203685477588 && sign == -1)
			return (0);
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (sign * nbr);
}
