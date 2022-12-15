#include "../../include/cub3d.h"

void printErr(char *str)
{
	write(1, str, strlen(str));
	exit(EXIT_FAILURE);
}

bool space(int c)
{
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char *trim_space(char *str)
{
    char *end;

    // Trim leading space
    while (space((unsigned char)*str))
        str++;

    if (*str == 0)
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && space((unsigned char)*end))
        end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}