# Compiler
CC      := cc
#CFLAGS  := -g -Wall -Wextra -Werror
DFLAGS := -MMD -MP \
		 -I includes \
		 -I Libft/ \
		 -I MLX42/include
# Directories
OBJDIR  := objs

LIBMLX = MLX42
#GLFW_PATH = /Users/$(USER)/.brew/opt/glfw/lib/
GLFW_PATH := /opt/homebrew/Cellar/glfw/3.4/lib/
GLFW_INC := /opt/homebrew/Cellar/glfw/3.4/include/
 # <- previous one is not working on my macos
DFLAGS += -I $(GLFW_INC)

LIBFT_DIR := Libft
LIBFT_A := $(LIBFT_DIR)/libft.a

# Executable
NAME    := cub3d

# Source files
SRC     := srcs/main/main.c \
           srcs/parsing/00_parsing_main.c \
		   srcs/parsing/01_parsing_file.c \
		   srcs/parsing/02_parsing_meta.c \
		   srcs/parsing/03_parsing_utils.c \
		   srcs/parsing/parsing_checks.c \
		   srcs/parsing/parsing_map.c \
		   #srcs/execution/execution.c \
		   #srcs/execution/movement.c \
		   #srcs/execution/render.c \

# Object files
OBJ     := $(SRC:srcs/%.c=$(OBJDIR)/%.o)

# Colors
GREEN   := \033[0;32m
CYAN    := \033[0;36m
YELLOW  := \033[1;33m
RESET   := \033[0m

all: $(NAME)

$(LIBFT_A):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)
	@echo "$(CYAN)🚀 Built: $@$(RESET)"
$(LIBMLX):
	@echo "$(YELLOW)Cloning and building MLX42...$(NC)\n"
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) 
	@cd $(LIBMLX) && cmake -B build && cmake --build build -j4
	@echo "$(GREEN)MLX42 successfully built!$(NC)\n"

$(LIBFT_A):
	@make -s -C $(LIBFT_DIR)



$(OBJDIR)/%.o: srcs/%.c | $(LIBMLX)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

$(NAME): $(OBJ) $(LIBFT_A) $(LIBMLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBMLX)/build/libmlx42.a -lglfw -L"$(GLFW_PATH)" $(LIBFT_A) -o $(NAME)
	@echo "$(CYAN)🚀 Built: $@$(RESET)"
clean:
	@rm -rf $(OBJDIR)
	@make clean -s -C $(LIBFT_DIR)
	@echo "$(YELLOW)🧹 Cleaned Cub3d object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_DIR)
		@rm -rf $(LIBMLX)
	@echo "$(YELLOW)🗑️  Removed Cub3d binary.$(RESET)"

re: fclean all

.PHONY: all clean fclean re