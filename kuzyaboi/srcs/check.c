/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:41:36 by tstripeb          #+#    #+#             */
/*   Updated: 2019/07/30 13:50:28 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int ft_check_c(char *str, int i)
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

int ft_check_l(char *str)
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

int ft_height_c(char *str)
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

int ft_width_c(char *str)
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

int check(char **tetriminos)
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
