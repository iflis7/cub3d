#include "../../include/cub3d.h"

static size_t	static_get_color(char *src)
{
	UINT	len;

	len = 0;
	while (src[len] != '\0' && src[len] != ',')
	{
		if (!ft_isdigit(src[len]))
			ft_msg_err("Wrong color format!");
		len++;
	}
	if (atoi(src) > 255)
		ft_msg_err("Wrong color format.");
	return ((size_t)atoi(src));
}

