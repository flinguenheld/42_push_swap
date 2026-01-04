/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:23:22 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:56 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	buffer_size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buffer_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = ft_calloc(buffer_size, sizeof(char));
	if (new_str != NULL)
	{
		ft_strlcpy(new_str, s1, buffer_size);
		ft_strlcat(new_str, s2, buffer_size);
	}
	return (new_str);
}
