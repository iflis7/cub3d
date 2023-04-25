/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:49:37 by hsaadi            #+#    #+#             */
/*   Updated: 2023/04/25 18:49:39 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_mini_m	*ft_mini_mnew(char *line)
{
	t_mini_m	*mini_m;

	mini_m = malloc(sizeof(t_mini_m));
	if (!mini_m)
		return (NULL);
	mini_m->line = line;
	mini_m->next = NULL;
	mini_m->prev = NULL;
	return (mini_m);
}

t_mini_m	*ft_last_mini_m(t_mini_m *mini_m)
{
	if (!mini_m)
		return (NULL);
	while (mini_m->next)
		mini_m = mini_m->next;
	return (mini_m);
}

void	ft_mini_m_add_back(t_mini_m **mini_m, char *line)
{
	t_mini_m	*new;
	t_mini_m	*last;

	new = ft_mini_mnew(line);

	last = ft_last_mini_m(*mini_m);
	if (!last->line)
	{
		*mini_m = new;
		(*mini_m)->place++;
	}
	else
	{
		last->next = new;
        new->prev = last;
		(*mini_m)->place++;
	}
}
