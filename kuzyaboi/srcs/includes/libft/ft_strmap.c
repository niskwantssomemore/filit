/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:31:19 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 17:03:34 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*str;

	index = 0;
	if (s != 0 && f != 0)
	{
		if (!(str = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
			return (NULL);
		while (s[index] != '\0')
		{
			str[index] = f(s[index]);
			index++;
		}
		return (str);
	}
	return (0);
}
