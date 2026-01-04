/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:20:09 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:56 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	from;
	size_t	to;

	if (s1 == NULL || set == NULL)
		return (NULL);
	from = 0;
	to = ft_strlen(s1) -1;
	while (s1[from] && ft_strchr(set, s1[from]) != NULL)
		from++;
	while (to && ft_strrchr(set, s1[to]) != NULL)
		to--;
	return (ft_substr(s1, from, to - from + 1));
}
