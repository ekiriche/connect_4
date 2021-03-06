/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_over.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:05:01 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 14:05:45 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int		is_map_over(char **ans)
{
	int j;

	j = 0;
	while (ans[0][j] != '.' && ans[0][j] != '\0')
		j++;
	if (ans[0][j] == '\0')
		return (1);
	return (0);
}
