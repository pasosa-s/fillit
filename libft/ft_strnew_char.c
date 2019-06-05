/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:10:22 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/10 15:35:30 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_char(size_t size, char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_bchar(str, size + 1, c);
	return (str);
}
