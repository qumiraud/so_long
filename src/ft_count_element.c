/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:00:50 by quentin           #+#    #+#             */
/*   Updated: 2025/02/18 14:43:37 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_count_element_true(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;

	while (line [i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C' && line[i] != '\n')
			x++;
		i++;
	}
	if (x != 0)
		return (x);
		// changer le numero de renvoie  a la preference de monsieur
	return (0);
}

int	ft_count_element_p(char *line, int p)
{
	int	i;

	i = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			p++;
		}
		i++;
	}
	return (p);
}

int	ft_count_element_c(char *line, int c)
{
	int	i;

	i = 0;
	c = 0;

	while (line[i])
	{
		if (line[i] == 'C')
		{
			c++;
		}
		i++;
	}
	return (c);
}

int	ft_count_element_e(char *line, int e)
{
	int	i;

	i = 0;
	e = 0;
	while (line[i])
	{
		if (line[i] == 'E')
		{
			e++;
		}
		i++;

	}
	return (e);
}
