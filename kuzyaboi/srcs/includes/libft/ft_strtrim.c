/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:43:33 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/26 15:48:28 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_str(char const *s, int index)
{
	if (index == 0)
	{
		while (s[index] != '\0' && (s[index] == ' ' ||
					s[index] == '\n' || s[index] == '\t'))
			index++;
	}
	else if ((size_t)index == ft_strlen(s))
	{
		while (s[index - 1] == ' ' || s[index - 1] == '\n'
				|| s[index - 1] == '\t')
			index--;
	}
	return (index);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		index;
	int		i;

	if (s)
	{
		index = 0;
		i = 0;
		len = ft_strlen(s);
		index = read_str(s, index);
		if (s[index] == '\0')
			return (ft_strdup(""));
		len = read_str(s, len);
		if (!(str = ft_strnew(len - index + 1)))
			return (NULL);
		while (index + i <= len - 1)
		{
			str[i] = s[index + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
