/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentin <quentin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:00:50 by quentin           #+#    #+#             */
/*   Updated: 2025/02/13 16:17:04 by quentin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_element_p(char *line)//, int *p)
{
	int	i;
	int	p;

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
