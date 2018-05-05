/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:48:39 by ekiriche          #+#    #+#             */
/*   Updated: 2018/05/05 12:04:05 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

int	find_errors(char *str1, char *str2)
{
	char *temp1;
	char *temp2;

	temp1 = ft_itoa(ft_atoi(str1));
	temp2 = ft_itoa(ft_atoi(str2));
	if (ft_strcmp(temp1, str1) != 0 || ft_strcmp(temp2, str2) != 0 ||
		ft_atoi(str1) < 6 || ft_atoi(str2) < 7)
	{
		ft_memdel((void**)&temp1);
		ft_memdel((void**)&temp2);
		return (1);
	}
	ft_memdel((void**)&temp1);
	ft_memdel((void**)&temp2);
	return (0);
}

int 	width_of_array(char **map)
{
	int count;

	count = 0;
	while (map[0][count] != '\0')
		count++;
	return (count);
}

int		height_of_array(char **map)
{
	int count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

int		can_play(char **map, int j)
{
	if (map[0][j] != '.')
		return (-1);
	return (1);
}

void	unplay(char **map, int j)
{
	int i;

	i = 0;
	while (i < height_of_array(map))
	{
		if (map[i][j] != '.')
		{
			map[i][j] = '.';
			return ;
		}
		i++;
	}
}

void	play(char **map, int j, char c)
{
	int i;

	i = height_of_array(map) - 1;
	while (i >= 0)
	{
		if (map[i][j] == '.')
		{
			map[i][j] = c;
			return ; 
		}
		i--;
	}
}

int 	check_input(char **map, char *input)
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

int 	is_map_over(char **ans)
{
	int j;

	j = 0;
	while (ans[0][j] != '.' && ans[0][j] != '\0')
		j++;
	if (ans[0][j] == '\0')
		return (1);
	return (0);
}

int		is_map_won(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
				map[i][j] == 'X' && map[i + 1][j] == 'X' && map[i + 2][j] == 'X' &&
				map[i + 3][j] == 'X')
				return (1);
			if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
				map[i][j] == 'O' && map[i + 1][j] == 'O' && map[i + 2][j] == 'O' &&
				map[i + 3][j] == 'O')
				return (2);
			if (map[i][j] && map[i][j + 1] && map[i][j + 2] && map[i][j + 3] &&
				map[i][j] == 'X' && map[i][j + 1] == 'X' && map[i][j + 2] == 'X' &&
				map[i][j + 3] == 'X')
				return (1);
			if (map[i][j] && map[i][j + 1] && map[i][j + 2] && map[i][j + 3] &&
				map[i][j] == 'O' && map[i][j + 1] == 'O' && map[i][j + 2] == 'O' &&
				map[i][j + 3] == 'O')
				return (2);
			if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
				map[i][j] && map[i + 1][j + 1] && map[i + 2][j + 2] && map[i + 3][j + 3] &&
				map[i][j] == 'X' && map[i + 1][j + 1] == 'X' && map[i + 2][j + 2] == 'X' &&
				map[i + 3][j + 3] == 'X')
				return (1);
			if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
				map[i][j] && map[i + 1][j + 1] && map[i + 2][j + 2] && map[i + 3][j + 3] &&
				map[i][j] == 'O' && map[i + 1][j + 1] == 'O' && map[i + 2][j + 2] == 'O' &&
				map[i + 3][j + 3] == 'O')
				return (2);
			if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
				map[i][j] && map[i + 1][j - 1] && map[i + 2][j - 2] && map[i + 3][j - 3] &&
				map[i][j] == 'X' && map[i + 1][j - 1] == 'X' && map[i + 2][j - 2] == 'X' &&
				map[i + 3][j - 3] == 'X')
				return (1);
			if (map[i] && map[i + 1] && map[i + 2] && map[i + 3] &&
				map[i][j] && map[i + 1][j - 1] && map[i + 2][j - 2] && map[i + 3][j - 3] &&
				map[i][j] == 'O' && map[i + 1][j - 1] == 'O' && map[i + 2][j - 2] == 'O' &&
				map[i + 3][j - 3] == 'O')
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

char **create_map(int x, int y)
{
	char **ans;
	int i;
	int j;

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

int 	is_winning_play(char **map, int j)
{
	if (!can_play(map, j))
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

int 	is_winning_play_ai(char **map, int j)
{
	if (!can_play(map, j))
		return (0);
	play(map, j, 'O');
	if (is_map_won(map))
	{
		unplay(map, j);
		return (1);
	}
	unplay(map, j);
	return (0);
}

void	ai_plays(char **map)
{
	int j;
	int lul;

	j = 0;
	lul = 0;
	while (map[0][j] != '\0')
	{
		if (is_winning_play_ai(map, j) || is_winning_play(map, j))
		{
			play(map, j, 'O');
			return ;
		}
		j++;
	}
	lul = rand() % width_of_array(map);
	play(map, lul, 'O');
}

int main(int argc, char **argv)
{
	char **map;

	if (argc != 3 || find_errors(argv[1], argv[2]))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	map = create_map(ft_atoi(argv[1]), ft_atoi(argv[2]));
	int i = 0;
	char *buff;
	int turn = 0;
	while (1)
	{
		i = 0;
		{
			while (map[i])
			{
				ft_putendl(map[i]);
				i++;
			}
			if (turn % 2 == 0)
			{
				get_next_line(0, &buff);
				if (check_input(map, buff))
					ft_printf("Please, enter valid number :)\n");
				else
					play(map, ft_atoi(buff), 'X');
			}
			else
			{
				ai_plays(map);
			}
			turn++;
			if (is_map_won(map) == 1)
			{
				ft_printf("Player won!\n");
				return (0);
			}
			else if (is_map_won(map) == 2)
			{
				ft_printf("AI won!\n");
				return (0);
			}
			if (is_map_over(map))
			{
				ft_printf("Tie!");
				return (0);
			}
		}
		ft_memdel((void**)&buff);
	}
}
