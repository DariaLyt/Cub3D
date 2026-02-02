# Compiler
CC      := cc
CFLAGS  := -g #-Wall -Wextra -Werror
DFLAGS := -MMD -MP \
		 -I includes \
		 -I Libft/
# Directories
OBJDIR  := objs

LIBFT_DIR := Libft
LIBFT_A := $(LIBFT_DIR)/libft.a

# Executable
NAME    := cub3d

# Source files
SRC     := srcs/main/main.c \
           srcs/parsing/parsing_main.c \
		   srcs/parsing/parsing_utils.c \
		   srcs/parsing/parsing_checks.c


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

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

clean:
	@rm -rf $(OBJDIR)
	@make clean -s -C $(LIBFT_DIR)
	@echo "$(YELLOW)🧹 Cleaned Cub3d object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_DIR)
	@echo "$(YELLOW)🗑️  Removed Cub3d binary.$(RESET)"

re: fclean all

.PHONY: all clean fclean re