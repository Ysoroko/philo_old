# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 12:05:15 by ysoroko           #+#    #+#              #
#    Updated: 2021/08/17 15:38:39 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

EXECUTABLE = philo

GCC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

UTILS	=	utils/ft_output_utils.c \
			utils/ft_strings_utils.c \
			utils/ft_structure_utils.c \

SRC		=	$(UTILS) \
			main.c \

OBJS	=	$(SRC:.c=.o)

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

COMPILED = echo "\n📖 $(BOLD_PURPLE)Executable $(BOLD_CYAN)\"$(EXECUTABLE)\" $(BOLD_PURPLE)created and ready for use!\n$(NO_COLOR)"

# ------------------------------ Rules ------------------------------

all:	$(NAME)

$(NAME): $(OBJS)
		@$(COMP_START)
		@$(GCC) $(FLAGS) $(OBJS) -o $(EXECUTABLE)
		@$(COMPILED)

clean:
		@rm -rf $(OBJS)
		@$(CLEANED)

fclean: clean
		@rm -rf $(EXECUTABLE)
		@$(FCLEANED)

re:		fclean all

.c.o:
	@${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

.PHONY:	all clean fclean re
