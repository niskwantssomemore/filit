/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:32:35 by tstripeb          #+#    #+#             */
/*   Updated: 2019/07/18 15:34:49 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <stdio.h>

void ft_error()
{
	write(1, ERROR, 6);
}

char *ft_read_file(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*s;
	
	temp = NULL;
	if (!(read(fd, buf, 0) < 0))
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			if (temp)
			{
				s = ft_strjoin(temp, buf);
				ft_strdel(&temp);
				temp = ft_strdup(s);
				ft_strdel(&s);
			}
			else
				temp = ft_strdup(buf);
		}
		return (temp);
	}
	return (NULL);
}

int counter_of_tetriminos(char *buf)
{
	int counter;
	int index;
	int numb;

	counter = 0;
	index = 0;
	numb = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
		{
			numb++;
			if (numb % 5 == 0 && numb != 0)
				counter++;
		}
		index++;
	}
	if (index)
		counter++;
	return (counter);
}

int main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		check_all;

	number = 0;
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		if (!(str = ft_read_file(fd)))
			ft_error();
		close(fd);
		printf("str:\n%s\n", str);
		number = counter_of_tetriminos(str);
		printf("number:\n%d\n", number);
		check_all = check(tetriminos);
	}
	else
		ft_error();
	return (0);
}
