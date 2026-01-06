### Libft

My beautifull libft that I lovely use and complete with all 42 C projects 😘  

- is
  - [int			ft_is_integer(char *str);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_is_integer.c)
  - [int			ft_isalnum(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_isalnum.c)
  - [int			ft_isalpha(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_isalpha.c)
  - [int			ft_isascii(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_isascii.c)
  - [int			ft_isdigit(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_isdigit.c)
  - [int			ft_isprint(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_isprint.c)
  - [int			ft_isspace(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_is/ft_isspace.c)
- list
  - [void		ft_lst_clear(t_list **lst, void (*del)(void *));](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_clear.c)
  - [void		ft_lst_clear_basic(t_list **lst);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_clear.c)
  - [int		ft_lst_contains(t_list *lst, int (*comparison)(void *))](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_contains.c)
  - [int		ft_lst_contains_key(t_list *lst, void *key, int (*comp)(void *, void *))](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_contains.c)
  - [void		ft_lst_delone(t_list *lst, void (*del)(void *));](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_delone.c)
  - [void		ft_lst_delone_basic(t_list *lst);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_delone.c)
  - [void		ft_lst_iter(t_list *lst, void (*f)(void *));](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_iter.c)
  - [t_list	*ft_lst_last(t_list *lst);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lstlast.c)
  - [t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *));](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_map.c)
  - [t_list	*ft_lst_new(void *content);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_new.c)
  - [t_list	*ft_lst_pop_back(t_list **lst, t_list *new_node);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_pop_back.c)
  - [t_list	*ft_lst_pop_front(t_list **lst, t_list *new_node);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_pop_front.c)
  - [void		ft_lst_push_back(t_list **lst, t_list *new_node);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_push_back.c)
  - [void		ft_lst_push_front(t_list **lst, t_list *new_node);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_push_front.c)
  - [void		ft_lst_rotate_left(t_list **lst);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_rotate_left.c)
  - [void		ft_lst_rotate_right(t_list **lst);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_rotate_right.c)
  - [int		ft_lst_size(t_list *lst);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_size.c)
  - [void		ft_lst_swap_content(t_list *a, t_list *b);](https://github.com/flinguenheld/42_libft/blob/master/ft_list/ft_lst_swap_content.c)
- malloc
  - [void		*ft_calloc(size_t nmemb, size_t size);](https://github.com/flinguenheld/42_libft/blob/master/ft_malloc/ft_calloc.c)
- mem
  - [void		ft_bzero(void *s, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_bzero.c)
  - [void		*ft_memrchr(const void *s, int c, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memchr.c)
  - [int			ft_memcmp(const void *s1, const void *s2, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memcmp.c)
  - [void		*ft_memcpy(void *dest, const void *src, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memcpy.c)
  - [void		*ft_memmove(void *dest, const void *src, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memmove.c)
  - [void		*ft_memchr(const void *s, int c, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memrchr.c)
  - [void		*ft_memset(void *s, int c, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memset.c)
  - [void		*ft_memset(void *s, int c, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_memset.c)
  - [void		ft_swap(void **a, void **b);](https://github.com/flinguenheld/42_libft/blob/master/ft_mem/ft_swap.c)
- printf
  - [int			ft_printf(const char *str, ...);](https://github.com/flinguenheld/42_libft/blob/master/ft_printf)
  - [int			ft_printf_err(const char *str, ...);](https://github.com/flinguenheld/42_libft/blob/master/ft_printf)
- put
  - [void		ft_putchar_fd(char c, int fd);](https://github.com/flinguenheld/42_libft/blob/master/ft_put/ft_putchar_fd.c)
  - [void		ft_putendl_fd(char *s, int fd);](https://github.com/flinguenheld/42_libft/blob/master/ft_put/ft_putendl_fd.c)
  - [void		ft_putnbr_fd(int n, int fd);](https://github.com/flinguenheld/42_libft/blob/master/ft_put/ft_putnbr_fd.c)
  - [void		ft_putstr_fd(char *s, int fd);](https://github.com/flinguenheld/42_libft/blob/master/ft_put/ft_putstr_fd.c)
- str
  - [char		**ft_split(char const *s, char c);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_split.c)
  - [char		*ft_strchr(const char *s, int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strchr.c)
  - [char		*ft_strdup(const char *s);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strdup.c)
  - [void		ft_striter(char *s, int (*f)(int));](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_striter.c)
  - [void		ft_striteri(char *s, void (*f)(unsigned int, char*));](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_striteri.c)
  - [char		*ft_strjoin(char const *s1, char const *s2);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strjoin.c)
  - [size_t	ft_strlcat(char *dst, const char *src, size_t size);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strlcat.c)
  - [size_t	ft_strlcpy(char *dst, const char *src, size_t size);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strlcpy.c)
  - [size_t	ft_strlen(const char *s);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strlen.c)
  - [char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strmapi.c)
  - [int		ft_strncmp(const char *s1, const char *s2, size_t n);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strncmp.c)
  - [char		*ft_strnstr(const char *big, const char *little, size_t len);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strnstr.c)
  - [char		*ft_strrchr(const char *s, int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strrchr.c)
  - [char		*ft_strtrim(char const *s1, char const *set);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_strtrim.c)
  - [char		*ft_substr(char const *s, unsigned int start, size_t len);](https://github.com/flinguenheld/42_libft/blob/master/ft_str/ft_substr.c)
- to
  - [int		ft_atoi(const char *str);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_atoi.c)
  - [int		ft_atol(const char *str);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_atol.c)
  - [char		*ft_itoa(int value);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_itoa.c)
  - [char		*ft_itohex(int value);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_itohex.c)
  - [char		*ft_ltoa(long value);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_ltoa.c)
  - [char		*ft_ltobase(long value, char *base_str);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_u_ul_tobase.c)
  - [char		*ft_ltohex(long value);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_ltohex.c)
  - [int		ft_tolower(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_tolower.c)
  - [int		ft_toupper(int c);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_toupper.c)
  - [char		*ft_ultobase(unsigned long value, char *base_str);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_u_ul_tobase.c)
  - [char		*ft_utoa(unsigned int value);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_utoa.c)
  - [char		*ft_utohex(unsigned int value);](https://github.com/flinguenheld/42_libft/blob/master/ft_to/ft_utohex.c)

<div align="center" style="margin: 30px;">
  <a href="https://github.com/flinguenheld/chew">
      <img src="https://github.com/flinguenheld/chew/blob/main/images/squirrel_brown.png?raw=true">
  </a>
</div>
