/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:51:04 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/21 11:56:05 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
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
		ft_putchar('\n');
	}
}
