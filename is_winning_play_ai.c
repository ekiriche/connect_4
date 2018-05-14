/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_winning_play_ai.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:09:54 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 14:10:23 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int		is_winning_play_ai(char **map, int j)
{
	if (can_play(map, j) == -1)
	{
		return (0);
	}
	play(map, j, 'O');
	if (is_map_won(map))
	{
		unplay(map, j);
		return (1);
	}
	unplay(map, j);
	return (0);
}
