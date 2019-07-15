/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:34:58 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/21 12:08:08 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int index;

	index = 0;
	if (s1 && s2)
	{
		while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
			index++;
		if (s1[index] - s2[index] != 0)
			return (0);
		return (1);
	}
	return (0);
}
