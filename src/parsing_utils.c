/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:47:41 by pjurdana          #+#    #+#             */
/*   Updated: 2025/02/28 10:48:28 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_map_file_name(char *str, t_map **map_lines)
{
	int	i;
	int	parse_res;

	i = 0;
	parse_res = 0;
	while (str[i] != '\0')
		i++;
	if (i == 4)
		return (1);
	return (ref_map_file(str, i, parse_res, map_lines));
}
