# Compiler
CC      := cc
CFLAGS  := -Iincludes #-g -Wall -Wextra -Werror 

# Directories
OBJDIR  := objs
LIBDIR	:= libft

# Executable
NAME    := cub3d

# Source files
SRC     := srcs/main/main.c \
           srcs/parsing/parsing.c \

# Object files
OBJ     := $(SRC:srcs/%.c=$(OBJDIR)/%.o)

# Libft
LIBFT	:= $(LIBDIR)/libft.a

# Colors
GREEN   := \033[0;32m
CYAN    := \033[0;36m
YELLOW  := \033[1;33m
RESET   := \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -lreadline
	@echo "$(CYAN)🚀 Built: $@$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(CYAN)🚀 Built: $@$(RESET)"

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)🧹 Cleaned Cub3d object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)🗑️  Removed Cub3d binary.$(RESET)"

re: fclean all

.PHONY: all clean fclean re