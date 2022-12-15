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
    bool checker = false;

    tmp = get_next_line(fd);
    while (tmp)
    {
        if (only_one(tmp))
            checker = true;
        tmp = trim_space(tmp);
        if (tmp[0] != '1' || tmp[strlen(tmp) - 1] != '1')
            return (false);
        tmp = get_next_line(fd);
        if (!tmp)
            break;
    }
    free(tmp);
    if (!checker)
        printErr("Map invalid.\n");
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

int number_rows(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *line;
    int count = 1;

    line = get_next_line(fd);

    while (line)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        count++;
    }
    free(line);
    return (count);
}

bool check_last_line(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *line;
    int count = 0;
    int rows = number_rows(filename);

    line = get_next_line(fd);
    while (line)
    {

        if (count == rows - 1)
        {
            line = trim_space(line);
            while (*line)
            {
                if (*line != '1')
                    printErr("Map invalid.\n");
                line++;
            }
        }
        count++;
        line = get_next_line(fd);
        if (!line)
            break;
    }
    free(line);
    return (true);
}

bool parsing_map(char *filename)
{
    int fd;

    // check if path end with .cub
    if (strcmp(filename + strlen(filename) - 4, ".cub"))
        printErr("Map invalid.\n");

    fd = open(filename, O_RDONLY);
    if (fd <= 0)
        printErr("Map invalid.\n");

    check_map(fd);

    // check last line wall surrondered
    check_last_line(filename);

    return (true);
}

// check last line wall surrondered