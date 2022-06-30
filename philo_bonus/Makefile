NAME	=	philo_bonus
SRCS	=	philo_bonus.c utils_bonus.c init_bonus.c life_bonus.c
OBJ		=	$(SRCS:%.c=%.o)
INCLUDE	=	include/
HEADER	=	philo_bonus.h
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

clean:
			@$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
			@$(RM) $(NAME) $(NAME_B)

re:			fclean all