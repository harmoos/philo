CC		= cc
CFLAGS	= -Wall -Werror -Wextra -pthread -g3
NAME	= philo

SRC		= main.c parsing.c init.c time.c philo.c routine.c check_end.c

SRCS	= $(SRC)
OBJDIR	= obj/
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
CFLAGS	+= -I./

all : $(OBJDIR) $(NAME)

$(OBJDIR):
				mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				rm -rf $(OBJDIR)

fclean: clean
				rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
