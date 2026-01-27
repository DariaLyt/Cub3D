#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "structs.h"
# include "../libft/libft.h"

// Main
int run_game(char *map_name, t_game *game);

// Parsing
int parsing(char *map_name, t_game *game);
int fill_map_struct(t_game *game, char *file);
char *read_file(char *file);

// Execution

// Error & Cleanup

// Utils

// library?

#endif