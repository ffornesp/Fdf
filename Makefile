# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:47:31 by ffornes-          #+#    #+#              #
#    Updated: 2023/05/17 10:12:00 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

#MLX_DIR = mlx/
MLX_DIR = mlx_linux/
MLX_FILE = libmlx.a
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

HDR_FILES = fdf.h color_defs.h keycode_defs.h
HDR_DIR = include/
HDRS = $(addprefix $(HDR_DIR), $(HDR_FILES))

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_DIR = srcs/
SRC_FILES = fdf.c parse_input.c map_set.c set_points.c draw_screen.c key_hook.c \
			my_mlx.c line_renderer.c line_renderer_utils.c calculate_scale.c

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
CFLAGS =  
RM = rm -f
AR = ar rc
#INCLUDE = -I ./include/ -I ./libft/include -I ./mlx/
INCLUDE  = -I ./include/ -I ./libft/include/ -I ./mlx_linux/

###############################################################################
#									RULES									  #
###############################################################################

all: 		$(NAME) $(HDRS)

m_libft:
			@make -C $(LIBFT_DIR)
m_mlx:
			@make -C $(MLX_DIR) 2> ERRORS
			@rm ERRORS

$(NAME):	m_libft m_mlx $(OBJS_DIR) $(OBJS)
			@$(CC) $(INCLUDE) $(OBJS) -Llibft/ -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@
#@$(CC) $(INCLUDE) $(OBJS) -Llibft/ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o

$(OBJS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HDRS)
				$(CC) -Wall -Wextra -Werror -I/usr/include $(INCLUDE) -O3 -c $< -o $@

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
