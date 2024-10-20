CC = gcc 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
NAME = philo
SRCF = philo.c utils.c utils1.c utils2.c
OBJF = $(SRCF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJF)

clean :
	@rm -rf $(OBJF)
fclean : clean
	@rm -rf $(NAME)
re : clean all

.PHONY : all clean fclean re