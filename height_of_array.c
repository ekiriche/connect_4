/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_of_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:04:12 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 14:04:22 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int		height_of_array(char **map)
{
	int count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}
