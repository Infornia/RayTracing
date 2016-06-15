NAME =		rt

CC =		clang

CFLAGS +=	-Werror -Weverything

SRC =		$(shell ls -1 SOURCES)

INC	=		-I INCLUDES/
INC +=		-I libft/includes/
INC +=		-I minilibx/

LIB =	-L libft -lft
LIB +=	-L minilibx/ -lmlx -framework OpenGl -framework Appkit

OBJ =		$(patsubst %.c, obj/%.o, $(SRC))

ifeq ($(BUILD),d)
    CFLAGS += -g
endif
ifeq ($(BUILD),o)
    CFLAGS += -O3 -std=c89 -pedantic
endif

OS = 		$(shell uname -s)

ECHO = 		echo

ifeq ($(OS),Linux)
    ECHO += -e
endif

RM =		/bin/rm -rf

all	=		$(NAME)

$(NAME): 	obj $(OBJ)
	@make -C libft/
	@make -C minilibx/
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)
	@$(ECHO) "[\033[1;32m√\033[m]" $@

obj/%.o:	SOURCES/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@$(ECHO) "[\033[1;32m√\033[m]" $@

obj:
	@mkdir -p obj

clean:
	@$(ECHO) "\033[33;31mCleaning files .o ...\033[0m"
	@$(RM) obj/
	@make -C libft/ clean

fclean: 	clean

	@$(ECHO) "\033[33;31mCleaning executables...\033[0m"
	@$(RM) $(NAME)
	@make -C libft/ fclean
	@make -C minilibx/ clean

norme:
	norminette SOURCES/ $(INC)

re: 	fclean $(NAME)
