/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:55:39 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 13:56:22 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int		check_input(char **map, char *input)
{
	char *temp;

	temp = ft_itoa(ft_atoi(input));
	if (ft_strcmp(temp, input) != 0)
	{
		ft_memdel((void**)&temp);
		return (1);
	}
	ft_memdel((void**)&temp);
	if (ft_atoi(input) < 0 || ft_atoi(input) >= width_of_array(map))
		return (1);
	if (map[0][ft_atoi(input)] != '.')
		return (1);
	return (0);
}
