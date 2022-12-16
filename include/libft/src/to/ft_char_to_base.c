/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 08:18:31 by hsaadi            #+#    #+#             */
/*   Updated: 2022/10/29 03:04:19 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_char_to_base(unsigned char octet, size_t base)
{
	if (octet > base)
		ft_char_to_base(octet / base, base);
	write(1, &"0123456789ABCDEF"[octet % base], 1);
}
