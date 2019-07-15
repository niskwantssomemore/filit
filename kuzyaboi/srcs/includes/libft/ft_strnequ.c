/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:35:53 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/25 19:01:43 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (s1[index] == s2[index] && s1[index] != '\0'
				&& s2[index] != '\0' && index < n)
			index++;
		if (s1[index] - s2[index] != 0 && index < n)
			return (0);
		return (1);
	}
	return (0);
}
