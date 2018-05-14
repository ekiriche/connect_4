/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_winning_plays.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:56:38 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 13:57:12 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int		count_winning_plays(char **map)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (map[0][j] != '\0')
	{
		if (is_winning_play(map, j))
			count++;
		j++;
	}
	if (count >= 2)
		return (2);
	if (count == 1)
		return (1);
	return (0);
}
