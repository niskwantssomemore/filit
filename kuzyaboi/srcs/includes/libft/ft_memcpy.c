/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:51:47 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 17:10:14 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*srcs;

	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		dest[index] = srcs[index];
		index++;
	}
	return (dest);
}
