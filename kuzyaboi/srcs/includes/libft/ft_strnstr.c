/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:26:29 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 18:25:05 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	jndex;
	size_t	index;

	index = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[index] != '\0' && index < len)
	{
		if (str1[index] == str2[0])
		{
			jndex = 1;
			while (str1[index + jndex] == str2[jndex] &&
					str1[index + jndex] != '\0' && str2[jndex] != '\0'
					&& index + jndex < len)
				jndex++;
			if (str2[jndex] == '\0')
				return ((char *)(&str1[index]));
			else
				jndex = 0;
		}
		index++;
	}
	return (0);
}
