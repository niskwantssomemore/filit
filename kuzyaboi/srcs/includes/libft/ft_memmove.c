/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:59:16 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/26 16:29:46 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*srcs;
	size_t			index;

	index = 0;
	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	if (dest == srcs)
		return (dest);
	if (dest > srcs)
	{
		index = len;
		while (index-- > 0)
			dest[index] = srcs[index];
	}
	else
	{
		while (index < len)
		{
			dest[index] = srcs[index];
			index++;
		}
	}
	return (dest);
}
