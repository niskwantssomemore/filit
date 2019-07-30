/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighborscont.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:23:36 by sazalee           #+#    #+#             */
/*   Updated: 2019/07/30 17:08:27 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	ft_index_plus_one(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = ft_index_plus_one(str, index + 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = ft_index_plus_five(str, index + 5, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = ft_index_minus_five(str, index - 5, counter + 2, flag);
	return (counter);
}

int	ft_index_minus_one(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index - 1] == '#')
		counter = ft_index_minus_one(str, index - 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = ft_index_plus_five(str, index + 5, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = ft_index_minus_five(str, index - 5, counter + 2, flag);
	return (counter);
}

int	ft_index_plus_five(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = ft_index_plus_one(str, index + 1, counter + 2, flag);
	if (str[index - 1] == '#')
		counter = ft_index_minus_one(str, index - 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = ft_index_minus_five(str, index + 5, counter + 2, flag);
	return (counter);
}

int	ft_index_minus_five(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = ft_index_plus_one(str, index + 1, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = ft_index_plus_five(str, index - 5, counter + 2, flag);
	if (str[index - 1] == '#')
		counter = ft_index_minus_one(str, index - 1, counter + 2, flag);
	return (counter);
}

int	threeinarow(char *str, int index, int counter, int flag)
{
	if (str[index + 1] == '#')
		counter = ft_index_plus_one(str, index + 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = ft_index_plus_five(str, index + 5, counter + 2, flag);
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	return (counter);
}
