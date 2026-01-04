/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:58:24 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	full_size;

	ptr = NULL;
	full_size = nmemb * size;
	if (full_size == 0)
		return (malloc(0));
	if (full_size == 1 || full_size / nmemb == size)
	{
		ptr = malloc(full_size);
		if (ptr != NULL)
			ft_bzero(ptr, full_size);
	}
	return (ptr);
}
