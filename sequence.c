/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:29:02 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/22 20:29:02 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

/**
 * @brief
 * Loop in the list and clone all nodes which are in order
 * -> 5 7 15 22 100 ...
 * -> 54 33 5 2 ...
 * @return
 * The list with cloned values
 */
static t_list	*get_sequence(t_list *list)
{
	t_list	*ordered_values;

	ordered_values = NULL;
	while (list != NULL)
	{
		if (ordered_values == NULL || (content(list) > content(ordered_values)))
		{
			ft_lst_push_front(&ordered_values,
				ft_lst_new(new_content(content(list))));
		}
		list = list->next;
	}
	return (ordered_values);
}

/**
 * @brief
 * With the given list (which has been rotated),
 *  - get the current sequence
 *  - compare with the max and update if needed
 */
static void	get_n_compare(t_list *list, t_list **current_max)
{
	t_list	*current;

	current = get_sequence(list);
	if (ft_lst_size(current) > ft_lst_size(*current_max))
	{
		ft_lst_clear(current_max, free);
		*current_max = current;
	}
	else
		ft_lst_clear(&current, free);
}

static void *clone_content(void *content)
{
	int	*blah = malloc(sizeof(int));
	*blah = *(int *)content;
	return (blah);
}

static void blah(t_list *list, t_list *current, t_list **max)
{
	t_list *new_branch;

		print_ab(current, *max, "blah");
	if (list != NULL)
		ft_printf("now we check %d\n", content(list));

	if (list == NULL)
	{
		print_ab(current, *max, "this one");
		ft_printf("end\n");
		if (ft_lst_size(current) > ft_lst_size(*max))
		{
			ft_lst_clear(max, free);
			*max = current;
		}
		else
			ft_lst_clear(&current, free);
		return;
	}

	new_branch = NULL;
	// if (current == NULL)
	// {
	// 	t_list *raaaa = NULL;
	// 	ft_lst_push_front(&raaaa,
	// 		ft_lst_new(new_content(content(list))));
	// 	blah(list->next, raaaa, max);
	// }
		ft_printf("compare that: %d > %d \n", content(list) , content(current));
	if (current != NULL && content(list) > content(current))
	{
		new_branch = ft_lst_clone(current, clone_content);
		ft_lst_push_front(&new_branch,
			ft_lst_new(new_content(content(list))));
		blah(list->next, new_branch, max);
	}

	ft_printf("hello now we try with and without %d  -------------------------------------------\n", content(list));
	// new_branch = ft_lst_clone(current, clone_content);
	// blah(list->next, new_branch, max);
	blah(list->next, current, max);

}

static void *init_one(void)
{
	int *content;

	content = malloc(sizeof(int));
	*content = 1;
	return (content);
}

static void print_that(t_list *list)
{
	ft_printf("\n--\n");
	while (list != NULL)
	{
		ft_printf("%d ", *(int*)list->content);
		list = list->next;
	}
	ft_printf("\n--\n");
}

static void blahblah(t_list *list, t_list *sequence, t_list *seq_node_to_reach, int current_value)
{
	while (sequence != seq_node_to_reach)
	{
		if (current_value > content(list)
			&& content(sequence) == content(seq_node_to_reach))
			(*(int *)seq_node_to_reach->content) += 1;
		sequence = sequence->next;
		list = list->next;
	}
}

static t_list *extract_longest(t_list *list, t_list *sequences)
{
	t_list *sub;
	
	sub = NULL;
	while (list != NULL)
	{

		

		sequences = sequences->next;
		list = list->next;
	}

	return sub;
}

t_list	*longest_subsequence(t_list *list)
{
	t_list *sequences;
	t_list *sequences_iter;
	t_list *list_iter;

	sequences = ft_lst_init(ft_lst_size(list), &init_one);
	sequences_iter = sequences;
	list_iter = list;

	while (sequences_iter != NULL)
	{
		blahblah(list, sequences, sequences_iter, content(list_iter));
		sequences_iter = sequences_iter->next;
		list_iter = list_iter->next;
	}
	print_ab(list, sequences, "Dynamic prog");
	ft_lst_clear(&sequences, free);
	return (NULL);
}

t_list	*longest_sequence(t_list *list)
{
	int		len;
	t_list	*current;
	t_list	*current_max;

	current = NULL;
	current_max = NULL;
	len = ft_lst_size(list);

	longest_subsequence(list);

	
	// while (len--)
	// {
		// get_n_compare(list, &current_max);
		// ft_lst_push_front(&current,
		// 	ft_lst_new(new_content(content(list))));
		// blah(list, current, &current_max);
		// ft_lst_rotate_right(&list);

		ft_printf("bye\n");
	// }
	return (current_max);
}
