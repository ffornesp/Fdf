# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:47:31 by ffornes-          #+#    #+#              #
#    Updated: 2023/05/05 11:57:01 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

MLX_DIR = mlx/
MLX_FILE = libmlx.a
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_DIR = srcs/
SRC_FILES = fdf.c window_handler.c key_hook.c colors.c print_shape.c \
			line_renderer.c parse_input.c render_points.c

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
INCLUDE  = -I ./include/ -I ./libft/include/ -I ./mlx/

###############################################################################
#									RULES									  #
###############################################################################

all: 		$(NAME)

m_libft:
			@make -C $(LIBFT_DIR)
m_mlx:
			@make -C $(MLX_DIR)

$(NAME):	m_libft m_mlx $(OBJS_DIR) $(OBJS)
			@$(CC) $(INCLUDE) $(OBJS) -Llibft/ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(OBJS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

clean: 		
			make -C $(LIBFT_DIR) clean
			make -C $(MLX_DIR) clean
			@$(RM) $(OBJS)

fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			make -C $(MLX_DIR) clean
			@$(RM) $(NAME)

re:			fclean all
			

.PHONY: all clean fclean re
