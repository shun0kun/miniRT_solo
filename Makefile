NAME = minirt

SRCS_DIR = srcs/
SRCS_FILES = main.c \
			algebra/equation.c algebra/math.c \
			color/color.c \
			image/image_put_pixel.c \
			minirt/minirt.c \
			ray/ray_at.c \
			render/camera_ray.c render/object_hit.c render/render.c render/trace_ray.c \
			scene/parse_basics.c scene/parse_file.c scene/parse_numbers.c scene/parse_object.c scene/parse_values.c scene/scene_api.c \
			vec3/vec3_basic.c vec3/vec3_norm.c vec3/vec3_predicate.c vec3/vec3_product.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR = objs/
OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

LIBFT_DIR = libft/
LIBFT =$(LIBFT_DIR)libft.a

# MLX_DIR = minilibx_macos/
MLX_DIR = minilibx_linux/
MLX = $(MLX_DIR)libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)
# LIBS = $(LIBFT) $(MLX) -framework OpenGL -framework AppKit
LIBS = $(LIBFT) $(MLX) -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
