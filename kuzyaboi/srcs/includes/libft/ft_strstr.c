/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:24:10 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 18:07:13 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		index;
	int		jndex;

	index = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[index] != '\0')
	{
		if (str1[index] == str2[0])
		{
			jndex = 1;
			while (str1[index + jndex] != '\0' && str2[jndex] != '\0'
					&& str1[index + jndex] == str2[jndex])
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
