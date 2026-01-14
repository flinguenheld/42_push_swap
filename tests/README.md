*This project has been created as part of the 42 curriculum by [tghnassi](https://kakaoarbo.net/), [flinguen](https://linguenheld.net/), khebert*

## Libunit

### Description

This project allows you to easily launch and print [unit tests](https://en.wikipedia.org/wiki/Unit_testing).  
It requires to write test functions and follow some steps to add them.  
Once done, a simple make command will, execute all tests in separated forks and print their status which can be:
- OK
- KO
- Segmentation fault
- Bus error

### Installation

Clone this repository in the root of your project and name the folder **tests**.  
You can remove the **tests/.git** folder  
``` Bash
git clone https://github.com/flinguenheld/42_libunit tests
```

The purpose is to have this structure:  

```
- your_project/
        |   Makefile
        |   ...
        |-- tests/
        |     |   Makefile
        |     |   main.c
        |     |-- framework/
        |     |-- function_to_test_1/
        |     |        |   00_launcher.c
        |     |        |   01_unit_test.c
        |     |        |   02_unit_test.c
        |     |        |   ...
        |     |        |   function_to_test_1.h
        |     |        |
        |     |-- function_to_test_2/
        |     |        |   00_launcher.c
        |     |        |   01_unit_test.c
        |     |        |   02_unit_test.c
        |     |        |   ...
        |     |        |   function_to_test_2.h
        |     |        |
```

#### Steps

Use the **template test** to create the first test.  

1. Up **your** Makefile with a new rule *test*  
(also update your *clean* & *fclean* rules to propagate them)

``` Makefile
test: all
	@make -C tests/ --no-print-directory

clean:
	@make -C tests/ clean --no-print-directory

fclean: clean
	@make -C tests/ fclean --no-print-directory

.PHONY: all $(NAME) clean fclean re [...] test
```

2. Create folders (*function_to_test_1*, *function_to_test_2*, ...) in the **tests** with the name of a function you want to test.

3. Create files which will contain your test functions and a .h file with their prototypes.  
here **atol/atol_basic_test.c** for instance.  

``` C
#include "atol.h"

// The function has to have this prototype:
int	atol_basic_test(void)
{
	// And return either 1 for success or 0
	if (atol("2") == 2)
		return (1);
	else
		return (0);
}

```
4. Inside this new folder, create a `00_launcher.c` file.  
It will be in charge of launching your unit functions.  
(comment a *load_test* line to disable a test)  
Here an example:

``` C
#include "atol.h"

int	atol_launcher(t_count *final_count)
{
	// Create a list which will contain all your tests --
	t_list	*list;

	list = NULL;

	// Use this function to load a function test with a name --
	load_test(&list, "Test 2", &atol_basic_test); // Function ptr
	load_test(&list, "Test -2", &atol_negative_test);
	load_test(&list, "Test long max", &atol_max_test);
	...
	// Then launch them all with a title --
	return (launch_tests("ATOL", list, final_count));
}

```
5. Modify the *main.c*, its role is to execute your launchers.  
(comment a launcher to disable a group of tests)  

``` C
#include "is_int/is_int.h"
#include "lst_size/lst_size.h"
#include "atol/atol.h"
#include "memchr/memchr_test.h"

int	main(void)
{
	// Create and init a counter --
	t_count	s_count;

	s_count = counter_init();

	// Add here all your launchers --
	is_int_launcher(&s_count);
	// lst_size_launcher(&s_count);
	atol_launcher(&s_count);
	memchr_launcher(&s_count);

	// Print a summary of successful tests --
	print_final_counter(&s_count);
	if (s_count.success != s_count.total)
		return (-1);
	return (0);
}
```
6. Update the *tests Makefile*.  
This file has been pre-filled.  
You have to add and add your new tests files in the **SRC** variable.  
The executable default name is **libunit_tester.exe**.

``` Makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libunit_tester.exe
LIBUNIT_FOLDER = framework/ 
LIBUNIT_FILE = framework/libunit.a

SRC =	main.c \
		folder/01_unit_test_you_want.c \

all: $(NAME)

OBJS := $(SRC:%.c=%.o)

$(NAME): libunit $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBUNIT_FILE)
	./$(NAME) || true

libunit:
	@make -C $(LIBUNIT_FOLDER)

clean:
	@rm -f $(OBJS)
	make -C $(LIBUNIT_FOLDER) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBUNIT_FOLDER) fclean

re: fclean all

.SILENT: $(OBJS) $(NAME)
.PHONY: all clean fclean re libunit
```

### Commands

To compile your project, the libunit framework, your tests and launch them,  
simply run this command in your root folder:  

``` bash
make test
```

And to clean all subfolders
``` bash
make clean
make fclean
```
