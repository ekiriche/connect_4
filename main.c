/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:48:39 by ekiriche          #+#    #+#             */
/*   Updated: 2018/05/06 20:30:33 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "power.h"

static int		f_part_one_(int argc, char **argv)
{
	if (argc != 3 || find_errors(argv[2], argv[1]))
	{
		ft_printf("%s%sERROR%s%s\n", BOL, RED, RES, NBOL);
		return (0);
	}
	return (1);
}

static int		f_part_two_(char **map)
{
	char	*buff;
	int		c;

	c = 0;
	while (!get_next_line(0, &buff))
		ft_printf("%sPlease, enter valid number 😀\n%s", RED, RES);
	while (check_input(map, buff))
	{
		c == 0 ? ft_printf("%sPlease, enter valid number 😀\n%s", RED, RES) : 0;
		c == 1 ? ft_printf("%sPlease, enter valid number 😡\n%s", RED, RES) : 0;
		c >= 2 ? ft_printf("%sPlease, enter valid number 🤯\n%s", RED, RES) : 0;
		c++;
		ft_memdel((void**)&buff);
		while (!get_next_line(0, &buff))
			ft_printf("%s Please, enter valid number 😀\n%s", RED, RES);
	}
	play(map, ft_atoi(buff), 'X');
	ft_memdel((void**)&buff);
	return (1);
}

static int		f_part_three_(int *turn, char **map, char **argv, int i)
{
	int flag;

	flag = 0;
	if (is_map_won(map) == 1)
	{
		flag = 1;
		(ft_printf("🏆%sPlayer won!%s🏆\n", GRN, RES)) && (*turn = -42);
	}
	else if (is_map_won(map) == 2)
	{
		flag = 1;
		(ft_printf("🧠%s AI won%s🧠!\n", CYN, RES)) && (*turn = -42);
	}
	if (is_map_over(map) && flag == 1)
		(ft_printf("🤝%sT%si%se%s🤝\n", RED, YEL, GRN, RES)) && (*turn = -42);
	if (ft_atoi(argv[2]) < 11)
		while (i < ft_atoi(argv[2]))
			(ft_printf("%i", i)) && (i++);
	ft_printf("\n");
	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
	return (1);
}

int				main(int argc, char **argv)
{
	int		i;
	int		turn;
	char	**map;

	if (!(f_part_one_(argc, argv)))
		return (0);
	srand(time(NULL));
	turn = rand() % 2;
	map = create_map(ft_atoi(argv[2]), ft_atoi(argv[1]));
	while (1)
	{
		i = 0;
		if (turn % 2 == 0)
			f_part_two_(map);
		else
			ai_plays(map);
		ft_printf("\n");
		turn++;
		f_part_three_(&turn, map, argv, i);
		if (turn == -42)
			break ;
	}
	return (0);
}
