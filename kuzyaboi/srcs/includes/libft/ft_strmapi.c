/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:33:16 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 17:04:05 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (s != 0 && f != 0)
	{
		if (!(str = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
			return (NULL);
		while (s[index] != '\0')
		{
			str[index] = f(index, s[index]);
			index++;
		}
		return (str);
	}
	return (0);
}
