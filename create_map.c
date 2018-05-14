/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:57:25 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 13:57:57 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

char	**create_map(int x, int y)
{
	char	**ans;
	int		i;
	int		j;

	ans = (char**)malloc(sizeof(char*) * (y + 1));
	i = 0;
	while (i < y)
	{
		j = 0;
		ans[i] = (char*)malloc(sizeof(char) * (x + 1));
		while (j < x)
		{
			ans[i][j] = '.';
			j++;
		}
		ans[i][j] = '\0';
		i++;
	}
	ans[i] = NULL;
	return (ans);
}
