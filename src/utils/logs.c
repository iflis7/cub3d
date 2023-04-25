/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:49:45 by hsaadi            #+#    #+#             */
/*   Updated: 2023/04/25 18:49:46 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_msg_err(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
	return (0);
}

int	ft_msg_err_close(char *error, int *fd)
{
	write(2, "Error\n", 6);
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
	close(*fd);
	return (0);
}