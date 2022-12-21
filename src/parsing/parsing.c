#include "../../include/cub3d.h"


// bool check_

bool validate_map(char *file)
{
    char *line;
    int fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        printf("%s\n", line);
        line = get_next_line(fd);
    }
    return (true);
}

bool parse_map(t_cub *cub, char *file)
{
    if (!access_test(file, ".cub"))
        return (ft_msg_err("Map file not found."));
    
    if (!validate_map(file))
        return (ft_msg_err("Invalid map."));
    printf("cub->name = %s\n", cub->name); // just to silence the error for now
    return (true);
}