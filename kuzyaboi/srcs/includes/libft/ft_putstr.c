/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:49:48 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/21 11:55:27 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int index;

	index = 0;
	if (s)
	{
		while (s[index] != '\0')
		{
			ft_putchar(s[index]);
			index++;
		}
	}
}
