/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:58:13 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/03 17:16:55 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
DESCRIPTION
Adds the substr ptr into to_fill.
Increments to_fill

Returns one on success (or on dry run) and a negative value on malloc fail
*/
static int	fill(char ***to_fill, const char *s, size_t length)
{
	char	*new_str;

	if (*to_fill != NULL && length > 0)
	{
		new_str = ft_substr(s, 0, length);
		if (new_str == NULL)
			return (INT32_MIN);
		**to_fill = new_str;
		(*to_fill)++;
	}
	return (1);
}

/*
DESCRIPTION
Loops in tab_to_clear and frees all substr.
Then frees tab_to_clear and sets it to NULL.
*/
static void	clear_and_free(char ***tab_to_clear)
{
	char	**word_to_clear;

	if (*tab_to_clear != NULL)
	{
		word_to_clear = *tab_to_clear;
		while (*word_to_clear != NULL)
		{
			free(*word_to_clear);
			*word_to_clear = NULL;
			word_to_clear++;
		}
		free(*tab_to_clear);
		*tab_to_clear = NULL;
	}
}

/*
DESCRIPTION
Recursively gets the next substr and add them in to_fill.
Excludes empty str.
to_fill = NULL to do a dry run.

Stops if one substr creation has failled and returns a negative value.

RETURN VALUE
The number of substrs or a negative value.
*/
static int	run(const char *str, char delimiter, char **to_fill, char ***start)
{
	char	*next_delimiter;

	if (*str == '\0')
		return (0);
	next_delimiter = ft_strchr(str, delimiter);
	if (next_delimiter == NULL || delimiter == '\0')
		return (fill(&to_fill, str, ft_strlen(str)));
	else if ((next_delimiter - str) > 0)
	{
		if (fill(&to_fill, str, next_delimiter - str) < 0)
			return (INT32_MIN);
		return (1 + run(next_delimiter + 1, delimiter, to_fill, start));
	}
	return (run(next_delimiter + 1, delimiter, to_fill, start));
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;

	tab = NULL;
	if (s != NULL)
	{
		count = run(s, c, NULL, &tab);
		tab = ft_calloc(count + 1, sizeof(char *));
		if (tab != NULL && run(s, c, tab, &tab) < 0)
			clear_and_free(&tab);
	}
	return (tab);
}
