/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:18:37 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/26 16:22:42 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_counter_words(char const *s, char c)
{
	int counter;
	int index;

	index = 0;
	counter = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			counter++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
		else
			index++;
	}
	return (counter);
}
