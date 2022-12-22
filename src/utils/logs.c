#include "../../include/cub3d.h"

int	ft_msg_err(char *error)
{
    write(2, "Error\n", 6);
    write(2, error, strlen(error));
    write(2, "\n", 1);
	exit(1);
	return (0);
}