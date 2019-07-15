/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:31:02 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 15:22:08 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
	{
		++index;
		if (index >= n)
			return (s1[index - 1] - s2[index - 1]);
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
