/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_da_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:58:15 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 19:20:22 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

static int	definetly_loses(char **map)
{
	int j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (is_winning_play(map, j) == 1)
			return (1);
		j++;
	}
	return (0);
}

static int	evade_lose(char **map, int k, int *flag)
{
	if (can_play(map, k) == 1)
	{
		play(map, k, 'X');
		if (count_winning_plays(map) == 2)
		{
			unplay(map, k) && (*flag = 1);
			return (1);
		}
		unplay(map, k);
	}
	return (0);
}

int			find_da_way(char **map, int j)
{
	int flag;
	int k;

	flag = 0;
	if (can_play(map, j) == -1)
		return (0);
	play(map, j, 'O');
	if (definetly_loses(map) == 1)
	{
		unplay(map, j);
		return (0);
	}
	k = -1;
	while (map[0][++k] != '\0')
	{
		if (evade_lose(map, k, &flag) == 1)
			break ;
	}
	unplay(map, j);
	if (flag == 1)
		return (0);
	return (1);
}
