#ifndef CUB_H
# define CUB_H

# include "../Libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Main
int		run_game(char *map_name, t_game *game);

// Map parsing
int		parsing(char *map_name, t_game *game);

// Map struct
void	init_game_struct(t_game *game);
int		fill_map_struct(t_game *game, char *file);

// Map parsing helpers
int is_empty_line(char *str);
int is_space(char c);
char *skip_spaces(char *str);
char	*ft_strjoin_and_free(char *map_whole, char *line);

// Execution

// Cleanup
void free_map(t_game *game);

// Error

// Parsing Utils

// Debug
void print_game_data(t_game *game);

#endif