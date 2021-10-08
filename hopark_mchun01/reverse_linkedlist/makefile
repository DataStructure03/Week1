NAME = reverse

CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj
vpath %.c $(SRC_DIR)

INCLUDE = $(addprefix $(INC_DIR)/, \
	../../hopark_mchun00/linkedlist/linkedlist.h \
)

SRC = $(addprefix $(SRC_DIR)/, \
	../../hopark_mchun00/linkedlist/linkedlist.c \
	reverse.c \
	reverse_test.c \
)


all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	./reverse


OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
$(OBJ_DIR ) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(INCLUDE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDE) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
