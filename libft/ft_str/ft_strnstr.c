/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:56:18 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:56 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len > 0)
	{
		while (*big && len-- >= little_len)
		{
			if (ft_strncmp(big, little, little_len) == 0)
				return ((char *)big);
			big++;
		}
	}
	return (NULL);
}
