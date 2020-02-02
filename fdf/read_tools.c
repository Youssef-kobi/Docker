/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytourame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 23:03:22 by ytourame          #+#    #+#             */
/*   Updated: 2020/01/17 22:55:11 by ytourame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int		**read_file(char *arg)
{
	int fd;
	int *xy;

	fd = open(arg, O_RDONLY);
	if (xy = get_dim(fd))
	{
		close(fd);
		fd = open(arg, O_RDONLY);
		return(get_corr(fd, xy[0], xy[1]));
	}
	else
		return(NULL);
}


int		*get_dim(int fd)
{
	int xy[2];
	int x;
	int y;
	int len;
	char *buff;
	char **tab;

	len = 0;
	y = 0;
	if (get_next_line(fd, buff) <= 0)
		return(NULL);
	tab = ft_strsplit(buff, ' ');
	x = ft_strlen(*tab);
	while(get_next_line(fd, buff) > 0)
	{
		tab = ft_strsplit(buff,' ');
		len = ft_strlen(*tab);
		y++;
		if (len < x)
			return(NULL);
	}
	xy[0] = x;
	xy[1] = y;
	return(xy);
}

int		**get_coor(int fd, int xmax, int ymax)
{
	int x;
	int y;
	char *buff;
	char **tab;
	int data[ymax][xmax];

	x = -1;
	y = -1;
	while (get_next_line(fd, buff) > 0 && y++ <= ymax)
	{
		free(*tab);
		tab = ft_strsplit(buff, ' ');
		while(x++ <= xmax)
			data[y][x] = ft_atoi(tab[x]);
	}
	return(data);
}
