/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flinguen <florent@linguenheld.net>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:46:57 by flinguen          #+#    #+#             */
/*   Updated: 2026/01/06 18:28:47 by flinguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

/**
 * List node.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ****************************************************************************/
/* ******************************************************************* IS *****/
/**
 * @brief
 * Check if the given str is an integer.
 * Valids:
 * "123"
 * " -123"
 * " +123"
 * "       +0"
 * Non valid
 * ""
 * "--123"
 * "123a"
 * "+ 12"
 * "-"
 * @return
 * 1 if str is a valid number otherwise 0.
 */
int			ft_is_integer(char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);

/* ****************************************************************************/
/* ***************************************************************** LIST *****/
/**
 * @brief
 * Deletes and frees the given node and all its successors, using the
 * function ’del’ and free(3). Finally, set the pointer to the list to NULL.
 */
void		ft_lst_clear(t_list **lst, void (*del)(void *));

/**
 * @brief
 * Wrapper of 'ft_lst_clear' which deletes all contents with the free fuction.
 */
void		ft_lst_clear_basic(t_list **lst);

/**
 * @brief
 * Loop in the list and apply the comparison on each node.
 * @return
 * 1 if one node's comparison is valid.
 */
int			ft_lst_contains(t_list *lst, int (*comparison)(void *));

/**
 * @brief
 * Loop in the list and apply the comparison on each node.
 * @return
 * 1 if one node's comparison is valid.
 */
int			ft_lst_contains_key(t_list *lst, void *key,
				int (*comp)(void *, void *));

/**
 * @brief
 * Takes a node as parameter and frees its content using the function ’del’.
 * Free the node itself but does NOT free the next node.
 */
void		ft_lst_delone(t_list *lst, void (*del)(void *));

/**
 * @brief
 * Wrapper of 'ft_lst_delone' which deletes the content with the 'free' fuction.
 */
void		ft_lst_delone_basic(t_list *lst);

/**
 * @brief
 * Iterates through the list ’lst’ and applies the
 * function ’f’ to the content of each node.
 */
void		ft_lst_iter(t_list *lst, void (*f)(void *));

/**
 * @brief
 * Returns the last node of the list.
 */
t_list		*ft_lst_last(t_list *lst);

/**
 * @brief
 * Iterates through the list ’lst’, applies the function ’f’ to each node’s
 * content, and creates a new list resulting of the successive applications of
 * the function ’f’.
 * The ’del’ function is used to delete the content of a node if needed.
 */
t_list		*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a new node.
 * The content member variable is initialized with the given parameter content.
 * The variable next is initialized to NULL.
 * 
 * @return
 * A pointer to the new node.
 */
t_list		*ft_lst_new(void *content);

/**
 * @brief
 * Pop the last node of the list.
 * Set lst to NULL if there was only one node left.
 * @return
 * The last node or NULL if lst is empty.
 */
t_list		*ft_lst_pop_back(t_list **lst);

/**
 * @brief
 * Pop the first node of the list.
 * Set list to the second node or NULL if there was only one node left.
 * @return
 * The first node or NULL if lst is empty.
 */
t_list		*ft_lst_pop_front(t_list **lst);

/**
 * @brief
 * Push the node ’new’ at the end of the list.
 */
void		ft_lst_push_back(t_list **lst, t_list *new_node);

/**
 * @brief
 * Push the node ’new’ at the beginning of the list.
 */
void		ft_lst_push_front(t_list **lst, t_list *new_node);

/**
 * @brief
 * Rotate the list of one position to the left.
 */
void		ft_lst_rotate_left(t_list **lst);

/**
 * @brief
 * Rotate the list of one position to the right.
 */
void		ft_lst_rotate_right(t_list **lst);

/**
 * @brief
 * Counts the number of nodes in the list.
 */
int			ft_lst_size(t_list *lst);

/**
 * @brief
 * Swap node contents.
 */
void		ft_lst_swap_content(t_list *a, t_list *b);

/* ****************************************************************************/
/* *************************************************************** MALLOC *****/
/*
 * @brief
 * The  calloc() function allocates memory for an array of nmemb elements of
 * size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * 
 * If nmemb or size is 0, calloc() returns a malloc(0) which returns a unique
 * pointer value that can be successfully passed to free().
 * 
 * If the multiplication of nmemb and size would result in integer overflow,
 * then calloc() returns a NULL.
 */
void		*ft_calloc(size_t nmemb, size_t size);

/* ****************************************************************************/
/* ****************************************************************** MEM *****/
/**
 * @brief
 * The  bzero()  function erases the data in the n bytes of the memory starting
 * at the location pointed to by s, by writing zeros (bytes containing '\0')
 *  to that area.
 * 
 * The explicit_bzero() function performs the same task as bzero().
 * It differs from bzero()  in  that  it guarantees that compiler optimizations
 *  will not remove the erase operation if the compiler deduces that
 *  the operation is "unnecessary".
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief
 * The  memrchr()  function  scans the initial n bytes of the memory area pointed
 * to by s for the first instance of c.
 * Both c and the bytes of the memory area pointed to by s are interpreted as
 * unsigned char.
 * 
 * @return
 * The  memchr() and  memrchr() functions return a pointer to the matching byte
 * or NULL if the character does not occur in the given memory area.
 */
void		*ft_memrchr(const void *s, int c, size_t n);

/**
 * @brief
 * The  memcmp() function compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 * 
 * @return
 * The memcmp() function returns an integer less than, equal to, or greater than
 * zero if the first n bytes of s1 is found, respectively, to be less than,
 * to match, or be greater than the first n bytes of s2.
 * 
 * For a nonzero return value, the sign is determined by the sign of the
 * difference between the first pair of bytes (interpreted as unsigned char)
 * that differ in s1 and s2.
 * 
 * If n is zero, the return value is zero.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief
 * The memcpy function copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap. Use memmove if the memory areas overlap.
 * @return
 * The memcpy() function returns a pointer to dest.
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief
 * The memmove function copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap: copying takes place as though the bytes in src
 * are first copied into a temporary array that does not overlap src or dest,
 * and * the bytes are then copied from the temporary array to dest.
 * 
 * @return
 * The memmove() function returns a pointer to dest.
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief
 * The  memchr()  function  scans the initial n bytes of the memory area pointed
 * to by s for the first instance of c.
 * Both c and the bytes of the memory area pointed to by s are interpreted as
 * unsigned char.
 * 
 * @return
 * The  memchr() and  memrchr() functions return a pointer to the matching byte
 * or NULL if the character does not occur in the given memory area.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief
 * The memset() function fills the first n bytes of the memory area pointed
 * to by s with the constant byte c.
 * 
 * @return
 * The memset() function returns a pointer to the memory area s.
 */
void		*ft_memset(void *s, int c, size_t n);

/**
 * @brief
 * Swap the two values pointed by a & b.
 */
void		ft_swap(void **a, void **b);

/* ****************************************************************************/
/* *************************************************************** PRINTF *****/
/**
 * @brief
 * Print str in the standard output and manage fields

 * Writes the pointed by format to the standard output.
 * If format includes format specifiers (subsequences beginning with %),
 * the additional arguments following format are formatted and inserted in the
 * resulting string replacing their respective specifiers.
 *
 * The following fields are managed:
 *  %c -> char
 *  %s -> string
 *  %p -> pointer
 *  %d -> decimal
 *  %i -> integer
 *  %u -> unsigned integer
 *  %x -> hexadecimal
 *  %X -> hexadecimal uppercase
 *  %% -> percent sign
 *
 * The function also accepts formats flags which are used as well:
 * (their behaviour can change according to the field type)
 *
 *  - -> Left-justify within the given field width
 *  + -> Prepends a plus sign for a positive value
 * ' ' -> Prepends a space character for a positive value; ignored if the
 *             + flag exists
 *  0 -> When the 'width' option is specified, prepends zeros instead of
 *             spaces for numeric types
 *  . -> Precision specifies the minimum number of digits to be written
 *  # -> for %x & % X -> 0x, 0X, respectively, is prepended to non-zero numbers
 * @return
 * The amount of printed char or -1 if error
 */
int			ft_printf(const char *str, ...);

/**
 * @brief
 * Same as ft_printf but in the standard output error.
 * @return
 * The amount of printed char or -1 if error
 */
int			ft_printf_err(const char *str, ...);

/* ****************************************************************************/
/* ****************************************************************** PUT *****/
/**
 * @brief
 * Outputs the character ’c’ to the specified file descriptor.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief
 * Outputs the string s to the specified file descriptor followed by a newline.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief
 * Outputs the integer ’n’ to the specified file descriptor.
 */
void		ft_putnbr_fd(int n, int fd);

/**
 * @brief
 * Outputs the string ’s’ to the specified file descriptor.
 */
void		ft_putstr_fd(char *s, int fd);

/* ****************************************************************************/
/* ****************************************************************** STR *****/
/**
 * @brief
 * Allocates memory (using malloc(3)) and returns an array of strings obtained
 * by * splitting ’s’ using the character ’c’ as a delimiter.
 * The array must end with a NULL pointer.
 * 
 * @return
 * The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief
 * The strchr() function returns a pointer to the first occurrence of
 * the character c in the string s.
 * 
 * @return
 * The strchr() function returns a pointer to the matched character
 * or NULL if the character is not found.
 * The terminating null byte is considered part of the string, so that if c is
 * specified as '\0', this function returns a pointer to the terminator.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief
 * The strdup() function returns a pointer to a new string which is a duplicate
 * of the string s.  Memory for the new string is obtained with malloc(3),
 * and can be freed with free(3).
 * 
 * @return
 * On success, the strdup() function returns a pointer to the duplicated string.
 * It returns NULL  if  insufficient memory was available, with errno set to
 * indicate the cause of the error.
 */
char		*ft_strdup(const char *s);

/**
 * @brief
 * Applies the function ’f’ to each character of the string passed as argument.
 * And replace them by the result of the function.
 */
void		ft_striter(char *s, int (*f)(int));

/**
 * @brief
 * Applies the function ’f’ to each character of the string passed as argument,
 * passing its index as the first argument. Each character is passed by
 * address to ’f’ so it can be modified if necessary.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
 * @brief
 * Allocates memory (using malloc(3)) and returns a new string.
 * Which is the result of concatenating ’s1’ and ’s2.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief
 * The strlcat function appends the NUL-terminated string src to the end of dst.
 * It will append at most size - strlen(dst)-1 bytes,
 * NUL-terminating the result.
 * 
 * @return
 * strlcat function returns the total length of the string it tried to create.
 * That means the initial length of dst plus the length of src.
 * While this may seem somewhat confusing, it was done to make truncation
 * detection simple.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief
 * The strlcpy() function copies up to size - 1 characters from the
 * NUL-terminated *  string src to dst, NUL-terminating the result.
 * 
 * @return
 * The strlcpy() function returns the total length of the
 * string they tried to create.
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief
 * Get the length of str '\0' excluded
 */
size_t		ft_strlen(const char *s);

/**
 * @brief
 * Applies the function f to each character of the string s, passing its index
 * as * the first argument and the character itself as the second.
 * A new string is * created using malloc to store the results from the
 * successive applications of f.
 * 
 * @return
 * The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief
 * The  strcmp() function compares the two strings s1 and s2.  The locale is not
 * taken into account (for a locale-aware comparison, see strcoll(3)).
 * The comparison is done using unsigned characters.
 * 
 *        strcmp() returns an integer indicating the result of the comparison:
 *        • 0, if the s1 and s2 are equal;
 *        • a negative value if s1 is less than s2;
 *        • a positive value if s1 is greater than s2.
 *        The strncmp() function is similar, except it compares only the first
 *        (at most) n bytes of s1 and s2.
 * 
 * @return
 * The strcmp() and strncmp() functions return an integer less than, equal to,
 * or greater than zero if  s1 (or  the  first  n bytes thereof) is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief
 * The strnstr() function locates the first occurrence of the null-terminated
 * string little in the string big, where not more than len characters are
 * searched.  Characters that appear after a ‘\0’ character are not searched.
 * 
 * @return
 * If little is an empty string, big is returned; if little occurs nowhere in
 * big, * NULL is returned; otherwise a pointer to the first character of
 * the first * occurrence of little is returned.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief
 * The strchr() function returns a pointer to the first occurrence of the
 *  character c in the string s.
 * 
 * @return
 * The strrchr() function returns a pointer to the matched character
 * or NULL if the character is not found.  The terminating null byte is
 * considered part of the string, so that if c is specified as
 * '\0', this function returns a pointer to the terminator.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters
 * from ’set’ removed from the beginning and the end.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a substring
 * from the string ’s’.
 * The substring starts at index ’start’ and has a maximum length of ’len’.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/* ****************************************************************************/
/* ******************************************************************* TO *****/
/**
 * @brief
 * Converts the initial portion of str to int.
 * Do not detect errors.
 * @return
 * The converted value or 0 on error.
 */
int			ft_atoi(const char *str);

/**
 * @brief
 * Converts the initial portion of str to long.
 * Do not detect errors.
 * @return
 * The converted value or 0 on error.
 */
long		ft_atol(const char *str);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in base 10.
 */
char		*ft_itoa(int value);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in base 16 uppercase.
 */
char		*ft_itohex(int value);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in base 10.
 */
char		*ft_ltoa(long value);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in the given base.
 */
char		*ft_ltobase(long value, char *base_str);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in base 16 uppercase.
 */
char		*ft_ltohex(long value);

int			ft_tolower(int c);
int			ft_toupper(int c);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in the given base.
 */
char		*ft_ultobase(unsigned long value, char *base_str);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in base 10.
 */
char		*ft_utoa(unsigned int value);

/**
 * @brief
 * Allocates memory (using malloc(3)) and returns a string representing the
 * value in base 16 uppercase.
 */
char		*ft_utohex(unsigned int value);

#endif
