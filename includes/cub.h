#ifndef CUB_H
# define CUB_H

# include "libft.h"
//# include "../MLX42/include/MLX42/MLX42.h"
# include "MLX42/MLX42.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# define MIN_WIDTH 384
# define MIN_HEIGHT 216
# define MINIMAP_SCALE 0.15
# define TILE_SIZE 64
# define STEP_SIZE 0.5
# define MINIMAP_SCALE 0.15

// Main
int		run_game(char *map_name, t_game *game);

// Map parsing
int		parsing(char *map_name, t_game *game);
int		parse_file(t_game *game, int fd);
int		convert_list_to_grid(t_game *game);

// Map Validity check
int		is_valid_map_line(char *line);
char	*find_file(char *map_name);

// Map struct
void	init_game_struct(t_game *game);
int		fill_map_struct(t_game *game, char *map_name);
void	update_map_dims(t_map *map, char *line);

// Metadata
int		is_metadata(t_game *game, char *line);
int		save_path(char **dest, char *src);
int		save_color(int *dest, char *src);

// Map list
int		add_to_map_list(t_game *game, char *line);

// Map parsing helpers
int		is_empty_line(char *str);
int		is_space(char c);
char	*skip_spaces(char *str);
char	*ft_strjoin_and_free(char *map_whole, char *line);
int		is_valid_char(char c);

// Cleanup
void	free_map(t_game *game);

// Error

// Parsing Utils

// Debug
void	print_game_data(t_game *game);

// Execution
int init_game(t_game *game);

// *movement
void    handle_movement(t_game *game);
int movement_delta(t_game *game, double *x, double *y);

// *render
void    render(t_game *game);
void draw_minimap(t_game *game);
#endif
