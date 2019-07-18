/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:41:36 by tstripeb          #+#    #+#             */
/*   Updated: 2019/07/18 13:24:44 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static int ft_check_c(char *str, int i)
{
	int grate;
	int pointer;
	int index;
	int carry;

	index = 0;
	while (str[index])
	{
		if (str[index] == '#')
			grate++;
		else if (str[index] == '.')
			pointer++;
		else if (str[index] == '\n')
			carry++;
		else
			return (0);
		index++;
	}
	if (grate == 4 && pointer == 12 &&
			((i == number - 1 && carry == 3) || carry == 4))
		return (1);
	return (0);
}

static int ft_check_l(char *str)
{
	int index;
	int flag;

	index = 0;
	flag = 1;
	while (str[index])
	{
		while (flag % 5 != 0 && str[index])
		{
			if (str[index] == '\n')
				return (0);
			index++;
			flag++;
		}
		if (str[index] != '\n')
		{
			if (str[index])
				return (0);
			break ;//return (1);
		}
		index++;
		flag++;
	}
	return (1);
}

static int ft_height_c(char *str)
{
	int index;
	int counter;

	index = 0;
	counter = 0;
	while (str[index])
	{
		while(str[index] && str[index] != '\n')
		{
			if (str[index] == '#')
			{
				counter++;
				while (str[index] && str[index] != '\n')
					index++;
				break ;
			}
			index++;
		}
		if (!str[index])
			break ;
		index++;
	}
	return (counter);
}

static int ft_width_c(char *str)
{
	int index;
	int counter;
	int flag;

	counter = 0;
	flag = 1;
	while (flag < 5)
	{
		index = 0;
		while (index < 4)
		{
			if (str[flag + 5 * index - 1] == '#')
			{
				counter++;
				break;
			}
			index++;
		}
		flag++;
	}
	return (counter);
}

static int ft_three_in_a_row(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = ft_three_in_a_row(str, index + 1, counter + 2);
	else if (str[index + 5] == '#')
		counter = ft_three_in_a_row(str, index + 5, counter + 2);
	else if (str[index - 1] == '#')
		counter = ft_three_in_a_row(str, index - 1, counter + 2);
	else if (str[index - 5] == '#')
		counter = ft_three_in_a_row(str, index - 5, counter + 2);
}

static int ft_neighbors_c(char *str, int height, int width)
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

static int ft_check_s(char *str)
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

static int check(char **tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i])
	{
		if (ft_check_c(tetriminos[i], i))
			if (ft_check_l(tetriminos[i]))
				if (!ft_check_s(tetriminos[i]))
					return (0);
			else
				return (0);
		else
			return (0);
		i++;
	}
	return (1);
}
