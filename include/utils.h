/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkode <bylkode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:24:08 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 17:16:23 by bylkode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include <stdbool.h>

# define UINT unsigned int
# define UNCH unsigned char

typedef struct s_mini_m
{
	char *line; // map line
	struct s_mini_m	*next;
	struct s_mini_m	*prev;
	int				coord[4];
	int				place;

}					t_mini_m;

/* *************** ***************           *************** *************** */
/*                                 FUNCTIONS                                 */
/* *************** ***************           *************** *************** */

/* ***************  LOGS  *************** */
int					ft_msg_err(char *error);

/* ***************  MAP_UTILS  *************** */
int					access_test(char *file, char *ext);
bool				is_empty_line(char *line);
int					is_map_line(char *line);

/* ***************  PARSE_UTILS  *************** */
void				print_map_lines(t_mini_m *line);
char				*get_identifier(char *line, char *str);
char				**duplicate_map(char **map);
void				free_map(char **map);

/* ***************  LST_OPS  *************** */
t_mini_m			*ft_mini_mnew(char *line);
t_mini_m			*ft_last_mini_m(t_mini_m *lst);
void				ft_mini_m_add_back(t_mini_m **lst, char *line);

#endif
