/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:31:19 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/29 03:04:19 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
  char *str;
  size_t i;

  if (!s)
    return (NULL);
  i = 0;
  str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
  if (!str)
    return (NULL);
  while (s[i]) {
    str[i] = f(i, s[i]);
    i++;
  }
  str[i] = '\0';
  return (str);
}
