/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:39:39 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/26 16:28:13 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_miss_c(char const *s, int index, int c)
{
	while (s[index] == c && s[index] != '\0')
		index++;
	return ((s[index] == '\0') ? -1 : index);
}

static int		ft_miss_char(char const *s, int index, int c)
{
	while (s[index] != c && s[index] != '\0')
		index++;
	return (index);
}

static char		*ftt_strcpy(char const *src, int index, int c)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(str) * ft_strlen(src))))
		return (0);
	while (src[index] != c && src[index] != '\0')
	{
		str[i] = src[index];
		index++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		**ft_error_str(char **str, int jndex)
{
	while (jndex > 0)
	{
		free(str[jndex]);
		jndex--;
	}
	str[0] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		index;
	char	**str;
	int		jndex;

	index = 0;
	jndex = 0;
	if (!s || !(str = (char **)malloc(sizeof(str) *
					(ft_counter_words(s, c) + 2))))
		return (0);
	index = ft_miss_c(s, index, c);
	if (index != -1)
	{
		while (jndex < ft_counter_words(s, c) && s[index] != '\0')
		{
			if (!(ftt_strcpy(s, index, c)))
				return (ft_error_str(str, jndex));
			str[jndex] = ftt_strcpy(s, index, c);
			index = ft_miss_char(s, index, c);
			index = ft_miss_c(s, index, c);
			jndex++;
		}
	}
	str[jndex] = NULL;
	return (str);
}
