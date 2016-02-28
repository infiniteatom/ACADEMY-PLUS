MKEX = cc -o

SRC = main.c
FLAGS = -Wall -Wextra -Werror
OBJECT = $(SRC:.c=.o)
COMP = cc -c
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJECT)
	@$(MKEX) $(NAME) $(OBJECT) -L /usr/X11/lib -lmlx -lXext -lX11 -L libft/ -lft

$(OBJECT) :
	@make -C libft/
	@$(COMP) $(SRC) $(FLAGS) -I./ -I /usr/X11/include/ -I libft/
	@echo "Compilation of C files succesful"

clean :
	@/bin/rm -f $(OBJECT)


fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
