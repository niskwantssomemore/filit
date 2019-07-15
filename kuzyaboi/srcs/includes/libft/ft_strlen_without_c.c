/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_without_c.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:07:29 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/26 15:10:09 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_without_c(const char *s, int c)
{
	size_t counter;
	size_t index;

	if (s)
	{
		counter = 0;
		index = 0;
		while (s[index] != '\0')
		{
			if (s[index] != c)
				++counter;
			index++;
		}
		return (counter);
	}
	return (0);
}
