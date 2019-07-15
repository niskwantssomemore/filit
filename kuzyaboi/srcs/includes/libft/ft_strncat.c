/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:15:36 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 17:21:04 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t i;

	index = 0;
	i = 0;
	while (s1[index] != '\0')
		index++;
	while (s2[i] != '\0' && i < n)
	{
		s1[index + i] = s2[i];
		i++;
	}
	s1[index + i] = '\0';
	return (s1);
}
