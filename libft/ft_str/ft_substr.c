/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:03:02 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:56 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len == 0 || start >= s_len)
	{
		start = 0;
		len = 0;
	}
	else if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (sub != NULL)
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
