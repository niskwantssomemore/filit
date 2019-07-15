/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:17:44 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/22 15:26:20 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlength;
	size_t slength;
	size_t index;
	size_t jndex;

	jndex = 0;
	index = 0;
	dlength = ft_strlen(dst);
	slength = ft_strlen(src);
	if (size <= dlength)
		return (size + slength);
	while (dst[index] != '\0')
		index++;
	while (src[jndex] != '\0' && index < size - 1)
	{
		dst[index] = src[jndex];
		index++;
		jndex++;
	}
	dst[index] = '\0';
	return (dlength + slength);
}
