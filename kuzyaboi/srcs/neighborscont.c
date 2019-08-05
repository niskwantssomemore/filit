/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighborscont.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:23:36 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/05 16:46:17 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	indexplusone(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = indexplusone(str, index + 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = indexplusfive(str, index + 5, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = indexminufive(str, index - 5, counter + 2, flag);
	return (counter);
}

int	indexminusone(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index - 1] == '#')
		counter = indexminusone(str, index - 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = indexplusfive(str, index + 5, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = indexminufive(str, index - 5, counter + 2, flag);
	return (counter);
}

int	indexplusfive(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = indexplusone(str, index + 1, counter + 2, flag);
	if (str[index - 1] == '#')
		counter = indexminusone(str, index - 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = indexminufive(str, index + 5, counter + 2, flag);
	return (counter);
}

int	indexminufive(char *str, int index, int counter, int flag)
{
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	if (str[index + 1] == '#')
		counter = indexplusone(str, index + 1, counter + 2, flag);
	if (str[index - 5] == '#')
		counter = indexplusfive(str, index - 5, counter + 2, flag);
	if (str[index - 1] == '#')
		counter = indexminusone(str, index - 1, counter + 2, flag);
	return (counter);
}

int	threeinarow(char *str, int index, int counter, int flag)
{
	if (str[index + 1] == '#')
		counter = indexplusone(str, index + 1, counter + 2, flag);
	if (str[index + 5] == '#')
		counter = indexplusfive(str, index + 5, counter + 2, flag);
	if (counter == 6 && flag != 1)
		return (counter);
	else if (counter == 8)
		return (counter);
	return (counter);
}
