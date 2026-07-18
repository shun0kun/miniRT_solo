NAME = minirt

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX = minilibx_macos/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft -lminilibx_macos
LIBS = $(LIBFT) $(MLX)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJS)

%.o: %.c:
	$(CC)

clean:
	rm -rf $(OBJS_DIR)


fclean:
	rm -f $(NAME)



