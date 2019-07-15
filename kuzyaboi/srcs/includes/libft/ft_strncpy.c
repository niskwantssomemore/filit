/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:12:46 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/21 14:02:47 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str, const char *src, size_t n)
{
	size_t index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		str[index] = src[index];
		index++;
	}
	while (index < n)
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}
