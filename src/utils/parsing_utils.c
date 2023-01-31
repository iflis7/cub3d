#include "../../include/cub3d.h"

/**
 * @brief Checks if the line is surrondered by wall (1)
 * 
 * @param line The line to check
 * @return true if the line is surrondered by wall (1)
 * @return false if the line is not surrondered by wall (1)
 */
bool	only_one(char *line)
{
	while (*line != '\n')
	{
		if (*line != ' ' && *line != '1')
			return (false);
		line++;
	}
	return (true);
}

/**
 * @brief Checks if the line is surrondered by wall (1)
 * 
 * @param fd The file descriptor of the map file to check
 * @return true The line is surrondered by wall (1)
 * @return false The line is not surrondered by wall (1)
 */
// bool	surrondered_by_wall(int fd)
// {
// 	char	*tmp;
// 	bool	checker;

// 	checker = false;
// 	tmp = get_next_mini_m(fd);
//     if (!tmp)
//         printErr("Map invalid.\n");
// 	while (tmp)
// 	{
// 		if (only_one(tmp))
// 			checker = true;
// 		tmp = trim_space(tmp);
// 		if (tmp[0] != '1' || tmp[strlen(tmp) - 1] != '1')
// 			return (false);
// 		tmp = get_next_mini_m(fd);
// 	}
// 	free(tmp);
// 	if (!checker)
// 		printErr("Map invalid.\n");
// 	return (true);
// }

// bool	surrondered_by_wall(char *line )
// {
// 	bool	checker;

// 	checker = false;
// 	if (only_one(line))
// 		checker = true;
// 	tmp = trim_space(tmp);
// 	if (tmp[0] != '1' || tmp[strlen(tmp) - 1] != '1')
// 		return (false);
// 	tmp = get_next_mini_m(fd);

// 	free(tmp);
// 	if (!checker)
// 		printErr("Map invalid.\n");
// 	return (true);
// }