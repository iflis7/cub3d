/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 06:05:35 by hsaadi            #+#    #+#             */
/*   Updated: 2022/12/21 06:07:01 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_str_chr_num(char *str, int c)
{
	if (!str)
		return (0);
	if (c == '\0')
		return (1);
	while (*str)
		if (*(str++) == (char)c)
			return (1);
	return (0);
}
