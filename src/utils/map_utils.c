#include "../../include/cub3d.h"

int access_test(char *file, char *ext)
{
    int fd;

    if (strcmp(file + strlen(file) - 4, ext))
		  ft_msg_err("Wrong file type.");
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}