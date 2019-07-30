/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:45:02 by tstripeb          #+#    #+#             */
/*   Updated: 2019/07/30 13:50:16 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int ft_neighbors_c(char *str, int height, int width)
{
	int index;
	int counter;
	int flag;

	index = 0;
	counter = 0;
	flag = 0;
	while (str[index])
	{
		while (str[index] != '\n' && str[index])
		{
			if (str[index] == '#' && height == 2 && width == 2)
			{
				flag = 1;
				return ((ft_three_in_a_row(str, index, counter, flag) == 8) ? 1 : 0);
			}
			else if (str[index] == '#' && ((height == 1 && width == 3) ||
						(width == 1 && height == 3)))
				return ((ft_three_in_a_row(str, index, counter, flag) == 6 ) ? 1 : 0);
			index++;
		}
		index++;
	}
	return (0);
}

int ft_check_s(char *str)
{
	int height;
	int width;

	height = ft_height_c(str);
	width = ft_width_c(str);
	if ((height == 1 && width != 4) || (width == 1 && height != 4) ||
			(height == 3 && width != 2) || (width == 3 && height != 2) ||
			(height == 2 && width != 2) || (width == 2 && height != 2))
		return (0);
	if (ft_neighbors_c(str, height, width))
		return (1);
	return (0);
}

