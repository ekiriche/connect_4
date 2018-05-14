/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_winning_play.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:09:05 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 14:09:33 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int		is_winning_play(char **map, int j)
{
	if (can_play(map, j) == -1)
		return (0);
	play(map, j, 'X');
	if (is_map_won(map))
	{
		unplay(map, j);
		return (1);
	}
	unplay(map, j);
	return (0);
}
