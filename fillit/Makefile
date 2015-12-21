NAME = fillit.a

SOURCE_FILES =				\
	extra_functions.c		\
	f_memory_allocation.c	\
	f_fill_it.c				\
	f_validation.c			\
	f_read.c				\
	fillit.c

OBJECT_FILES = $(subst .c,.o,$(SOURCE_FILES))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): objects
	@ar rc $(NAME) $(OBJECT_FILES)
	@ranlib $(NAME)
objects:
	@gcc -c $(SOURCE_FILES)

clean:
	@rm -f $(OBJECT_FILES)

fclean: clean
	@rm -f $(NAME)

compile: $(NAME)
	@gcc fillit.c $(NAME)

re: fclean all
