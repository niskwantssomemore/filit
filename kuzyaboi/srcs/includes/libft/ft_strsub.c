/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:37:51 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 20:23:56 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index;
	size_t			length;
	int				i;

	if (!s)
		return (0);
	length = ft_strlen(s);
	index = 0;
	i = 0;
	if (length < len + (size_t)start)
		return (0);
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	while (index < start)
		index++;
	while (index < (unsigned int)len + start)
	{
		str[i] = s[index];
		i++;
		index++;
	}
	str[i] = '\0';
	return (str);
}
