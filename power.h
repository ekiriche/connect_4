/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:58:42 by ekiriche          #+#    #+#             */
/*   Updated: 2018/05/06 19:47:58 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_H
# define POWER_H
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RES	"\x1B[0m"
# define BOL	"\033[1m"
# define NBOL	"\033[22m"
# include "./libft/ft_printf.h"
# include <time.h>

int			find_errors(char *str1, char *str2);
int			width_of_array(char **map);
int			height_of_array(char **map);
int			can_play(char **map, int j);
int			unplay(char **map, int j);
void		play(char **map, int j, char c);
int			check_input(char **map, char *input);
int			is_map_over(char **ans);
int			is_map_won(char **map);
char		**create_map(int x, int y);
int			is_winning_play(char **map, int j);
int			is_winning_play_ai(char **map, int j);
int			count_winning_plays(char **map);
int			find_da_way(char **map, int j);
void		ai_plays(char **map);

#endif
