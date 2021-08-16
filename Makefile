# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 12:05:15 by ysoroko           #+#    #+#              #
#    Updated: 2021/08/16 13:53:30 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

GCC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	-I include

UTILS	=	utils/ft_output_utils.c \
			utils/ft_strings_utils.c \

SRC		=	$(UTILS) \
			main.c

OBJS	=	SRC:.c=.o

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"


# ------------------------------ Rules ------------------------------

all:	$(NAME)

$(NAME):
		$(GCC) $(FLAGS) $(INCLUDE) $(SRC) -o $(NAME)

clean:
		@rm -rf $(OBJS)
		@$(CLEANED)

fclean: clean
		@rm -rf $(NAME)
		@$(FCLEANED)

re:		fclean all

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

.PHONY:	all philo clean fclean re .c.o
