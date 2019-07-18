/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:40:16 by tstripeb          #+#    #+#             */
/*   Updated: 2019/07/18 15:45:47 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int ft_index_plus_one(char *str, int index, int counter, int flag)
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

int ft_index_minus_one(char *str, int index, int counter, int flag)
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

int ft_index_plus_five(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = ft_index_plus_one(str, index + 1, counter + 2, flag);
	if (str[index - 1] == '#')
		counter = ft_index_minus_one(str, index - 1, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = ft_index_minus_five(str, index - 5, counter + 2, flag);
	return (counter);
}

int ft_index_minus_five(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = ft_index_plus_one(str, index + 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = ft_index_plus_five(str, index + 5, counter + 2, flag);
	if (str[index - 1] == '#')
		counter = ft_index_minus_one(str, index - 1, counter + 2, flag);
	return (counter);
}

int ft_three_in_a_row(char *str, int index, int counter, int flag)
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
