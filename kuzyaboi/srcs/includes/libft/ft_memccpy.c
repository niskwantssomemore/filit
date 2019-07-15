/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:56:18 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 17:25:52 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*srcs;

	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		if (srcs[index] != (unsigned char)c)
		{
			dest[index] = srcs[index];
			index++;
		}
		else
		{
			dest[index] = srcs[index];
			return (dest = &dest[++index]);
		}
	}
	return (0);
}
