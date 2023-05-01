# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:47:31 by ffornes-          #+#    #+#              #
#    Updated: 2023/05/01 11:48:45 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_DIR = srcs/
SRC_FILES =

###############################################################################
#									OBJS									  #
###############################################################################

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

###############################################################################
#									OTHER									  #
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
INCLUDE  = -I ./include/ -I ./libft/include/

###############################################################################
#									RULES									  #
###############################################################################

all: 		$(NAME)
bonus:		$(NAME_BONUS)

m_libft:
			@make -C $(LIBFT_DIR)

$(NAME):	m_libft $(OBJS_DIR) $(OBJS)
			@$(CC) $(INCLUDE) $(OBJS) -Llibft/ -lft -o $@

$(OBJS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS)

fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all
			

.PHONY: all clean fclean re bonus
