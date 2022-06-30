NAME	=	philo
SRCS	=	philo.c	utils.c	init.c life.c
OBJ		=	$(SRCS:%.c=%.o)
INCLUDE	=	include/
HEADER	=	philo.h
CC		=	gcc
FLAGS	=	-g -Wall -Wextra -Werror
RM		= rm -rf

all:		libft $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

clean:
			@$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
			@$(RM) $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all	clean	fclean	re	libft