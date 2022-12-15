#include "../../include/cub3d.h"

mlx_image_t *g_img;

void printErr(char *str)
{
	write(1, str, strlen(str));
	exit(EXIT_FAILURE);
}

void hook(void *param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

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

int main(int argc, char **argv)
{
	// t_cub3d *cub3d;

	if (argc != 2)
		printErr("Map is missing.\n");

	parsing_map(argv[1]);

	// cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	// cub3d->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// if (!cub3d->mlx)
	// 	exit(EXIT_FAILURE);

	// g_img = mlx_new_image(cub3d->mlx, 128, 128);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	// mlx_image_to_window(cub3d->mlx, g_img, 0, 0);
	// mlx_loop_hook(cub3d->mlx, &hook, cub3d->mlx);
	// mlx_loop(cub3d->mlx);
	// mlx_terminate(cub3d->mlx);
	return (EXIT_SUCCESS);
}
