/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:21:25 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/22 13:37:53 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		counter;
	char	*k;

	k = (char *)s;
	counter = 0;
	index = 0;
	if (c == '\0')
		return (k = &k[ft_strlen(k)]);
	while (k[index] != '\0')
	{
		if (k[index] == (char)c)
			counter++;
		++index;
	}
	index--;
	while (*k)
	{
		if (*k == (char)c && counter > 1)
			counter--;
		else if (*k == (char)c && counter == 1)
			return (k);
		k++;
	}
	return (NULL);
}
