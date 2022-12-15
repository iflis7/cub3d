#include "../../include/cub3d.h"

// check if line is only one and space
bool only_one(char *line)
{
    while (*line != '\n')
    {
        if (*line != ' ' && *line != '1')
            return (false);
        line++;
    }
    return (true);
}

// check if line is surrondered by wall (1)
bool surrondered_by_wall(int fd)
{
    char *tmp;

    tmp = get_next_line(fd);
    while (tmp)
    {
        tmp = trim_space(tmp);
        if (tmp[0] != '1' || tmp[strlen(tmp) - 1] != '1')
            return (false);
        tmp = get_next_line(fd);
        if (!tmp)
            break;
    }
    return (true);
}

bool check_map(int fd)
{
    char *line;
    bool checker = false;
    line = get_next_line(fd);
    while (line)
    {
        if (only_one(line))
        {
            checker = true;
            if (!surrondered_by_wall(fd))
                printErr("Map invalid.\n");
        }
        line = get_next_line(fd);
        if (!line)
            break;
    }
    if (!checker)
        printErr("Map invalid.\n");
    free(line);
    return (true);
}

bool parsing_map(char *filename)
{
    int fd;
    // char *line;

    // check if path end with .cub
    if (strcmp(filename + strlen(filename) - 4, ".cub"))
        printErr("Map invalid.\n");

    fd = open(filename, O_RDONLY);
    if (fd <= 0)
        printErr("Map invalid.\n");

    check_map(fd);

    return (true);
}