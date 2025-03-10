
NAME= fdf
CC= cc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft
MLX_DIR= ./libs/mlx
MLX= $(MLX_DIR)/libmlx.a
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs

SRCS= $(SRCS_DIR)/main.c $(SRCS_DIR)/free_displays.c $(SRCS_DIR)/drawlines.c \
$(SRCS_DIR)/get_map.c $(SRCS_DIR)/fdf_utils.c  $(SRCS_DIR)/drawmap.c $(SRCS_DIR)/ft_free.c \
$(SRCS_DIR)/get_scale.c $(SRCS_DIR)/colors.c $(SRCS_DIR)/init_window.c $(SRCS_DIR)/math.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory
	@echo "Cleaning Objects!"
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and executable"

re: fclean all

.PHONY: all clean fclean re


