#include "../../include/cub3d.h"

t_line	*ft_linenew(char *content)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->content = content;
	line->next = NULL;
	line->prev = NULL;
	return (line);
}

t_line	*ft_last_line(t_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_line_add_back(t_line **lst, char *line)
{
	t_line	*new;
	t_line	*last;

	new = ft_linenew(line);
    last = ft_last_line(*lst);

	if (!last->content)
	{
		*lst = new;
		(*lst)->place++;
	}
	else
	{
		last->next = new;
        (*lst)->place++;
	}
}


