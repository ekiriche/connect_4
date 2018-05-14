/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:03:28 by nmizin            #+#    #+#             */
/*   Updated: 2018/05/06 14:03:39 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

int	find_errors(char *str1, char *str2)
{
	char *temp1;
	char *temp2;

	temp1 = ft_itoa(ft_atoi(str1));
	temp2 = ft_itoa(ft_atoi(str2));
	if (ft_strcmp(temp1, str1) != 0 || ft_strcmp(temp2, str2) != 0 ||
		ft_atoi(str1) < 7 || ft_atoi(str2) < 6)
	{
		ft_memdel((void**)&temp1);
		ft_memdel((void**)&temp2);
		return (1);
	}
	ft_memdel((void**)&temp1);
	ft_memdel((void**)&temp2);
	return (0);
}
