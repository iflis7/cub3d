#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include <stdbool.h>

# define UINT unsigned int
# define UNCH unsigned char

typedef struct s_line
{
	char *content; // map line
	struct s_line	*next;
	struct s_line	*prev;
	int				place;
}					t_line;
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
void				print_map_lines(t_line *line);
char				*get_identifier(char *line, char *str);

/* ***************  LST_OPS  *************** */
t_line				*ft_linenew(char *content);
t_line				*ft_last_line(t_line *lst);
void				ft_line_add_back(t_line **lst, char *line);

#endif