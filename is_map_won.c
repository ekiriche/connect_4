/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_won.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:06:06 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 14:06:58 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

static int		f_part_one_(char **map, int i, int j)
{
	if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
		map[i][j] == 'X' && map[i + 1][j] == 'X' && map[i + 2][j] == 'X' &&
		map[i + 3][j] == 'X')
		return (1);
	if (map[i][j] && map[i][j + 1] && map[i][j + 2] && map[i][j + 3] &&
		map[i][j] == 'X' && map[i][j + 1] == 'X' && map[i][j + 2] == 'X' &&
		map[i][j + 3] == 'X')
		return (1);
	if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
		map[i][j] && map[i + 1][j + 1] && map[i + 2][j + 2] &&
		map[i + 3][j + 3] &&
		map[i][j] == 'X' && map[i + 1][j + 1] == 'X' &&
		map[i + 2][j + 2] == 'X' &&
		map[i + 3][j + 3] == 'X')
		return (1);
	if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
		map[i][j] && map[i + 1][j - 1] && map[i + 2][j - 2] &&
		map[i + 3][j - 3] &&
		map[i][j] == 'X' && map[i + 1][j - 1] == 'X' &&
		map[i + 2][j - 2] == 'X' &&
		map[i + 3][j - 3] == 'X')
		return (1);
	return (0);
}

static	int		f_part_two_(char **map, int i, int j)
{
	if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
		map[i][j] == 'O' && map[i + 1][j] == 'O' && map[i + 2][j] == 'O' &&
		map[i + 3][j] == 'O')
		return (2);
	if (map[i][j] && map[i][j + 1] && map[i][j + 2] && map[i][j + 3] &&
		map[i][j] == 'O' && map[i][j + 1] == 'O' && map[i][j + 2] == 'O' &&
		map[i][j + 3] == 'O')
		return (2);
	if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
		map[i][j] && map[i + 1][j + 1] && map[i + 2][j + 2] &&
		map[i + 3][j + 3] &&
		map[i][j] == 'O' && map[i + 1][j + 1] == 'O' &&
		map[i + 2][j + 2] == 'O' &&
		map[i + 3][j + 3] == 'O')
		return (2);
	if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
		map[i][j] && map[i + 1][j - 1] && map[i + 2][j - 2] &&
		map[i + 3][j - 3] &&
		map[i][j] == 'O' && map[i + 1][j - 1] == 'O' &&
		map[i + 2][j - 2] == 'O' &&
		map[i + 3][j - 3] == 'O')
		return (2);
	return (0);
}

int				is_map_won(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (f_part_one_(map, i, j) == 1)
				return (1);
			if (f_part_two_(map, i, j) == 2)
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}
