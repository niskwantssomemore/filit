/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:21:50 by tstripeb          #+#    #+#             */
/*   Updated: 2019/05/20 16:31:49 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = 0;
	if (size)
	{
		if (!(str = (unsigned char *)malloc(size)))
			return (0);
		ft_memset(str, 0, size);
	}
	return ((void *)str);
}
