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

// Parsing
int		parsing(char *map_name, t_game *game);
int		fill_map_struct(t_game *game, char *file);
char	*read_file(char *file);
char	*ft_strjoin_and_free(char *map_whole, char *line);

// Execution

// Error & Cleanup

// Utils

// library?

#endif