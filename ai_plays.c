/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_plays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:52:48 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 13:54:24 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

static void		f_part_one_(char **map, int lul)
{
	int dud;

	dud = 0;
	while (can_play(map, lul) == -1)
		lul = rand() % width_of_array(map);
	while (find_da_way(map, lul) == 0 && dud < 100)
	{
		lul = rand() % width_of_array(map);
		while (can_play(map, lul) == -1)
			lul = rand() % width_of_array(map);
		dud++;
	}
	play(map, lul, 'O');
}

void			ai_plays(char **map)
{
	int j;
	int lul;

	j = -1;
	while (map[0][++j] != '\0')
	{
		if (is_winning_play_ai(map, j) == 1)
		{
			play(map, j, 'O');
			return ;
		}
	}
	j = -1;
	while (map[0][++j] != '\0')
	{
		if (is_winning_play(map, j) == 1)
		{
			play(map, j, 'O');
			return ;
		}
	}
	lul = rand() % width_of_array(map);
	f_part_one_(map, lul);
}
