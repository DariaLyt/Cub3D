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
# define MINIMAP_SCALE 16
# define TILE_SIZE 64
# define STEP_SIZE 0.5
# define SPEED 0.00005
# define MOUSE_SENSITIVITY 0.025

# define GRAY_COLOR 2054449919
# define BLACK_COLOR 255
# define RED_COLOR 0xFF0000FF
# define COLLISION 0.15

// Main
int				run_game(char *map_name, t_game *game);

// Map parsing
int				parsing(char *map_name, t_game *game);
int				parse_file(t_game *game, int fd);
int				parse_line(t_game *game, char *line);
int				convert_list_to_grid(t_game *game);

// Map Validity check
int				is_valid_map_line(char *line);
int				is_valid_ext(char *map_name);

// Map struct
void			init_game_struct(t_game *game);
int				fill_map_struct(t_game *game, char *map_name);
void			update_map_dims(t_map *map, char *line);

// Metadata
int				is_metadata(t_game *game, char *line);
int				save_path(char **dest, char *src);
int				save_color(int *dest, char *src);
int				assign_rgb(char **m_str);
int				is_rgb_format(char *str);

// Map list
int				add_to_map_list(t_game *game, char *line);

// Floodfill
int				is_map_closed(t_game *game);
char			**ft_dup_map(t_game *game);
int				flood_fill(t_game *game, char **temp_grid, int x, int y);
int				find_player(t_game *game);
void			save_play_cord(t_game *game, char direction, int x, int y);

// Map parsing helpers
int				is_empty_line(char *str);
int				is_space(char c);
char			*skip_spaces(char *str);
char			*ft_strjoin_and_free(char *map_whole, char *line);
int				is_valid_char(char c);

// Cleanup
void			free_map(t_game *game);
void			free_tmp_map(char **map);
void			free_texture(t_game *game);

// Debug
void			print_game_data(t_game *game);

// Execution
int				init_game(t_game *game);

// dda.c
double			calc_delta(double dir);
void			init_dda_axis_x(t_game *game, t_dda *dda, double player,
					int map);
void			init_dda_axis_y(t_game *game, t_dda *dda, double player,
					int map);
void			init_dda(t_game *game, double angle, t_dda *dda);
void			perform_dda(t_game *game, t_dda *dda);

// execution.c
int				load_texture(char *path, mlx_texture_t **texture);
int				init_textures(t_game *game, t_texture *text);
int				init_mlx(t_game *game);
int				init_game(t_game *game);

// minimap.c
void			draw_minimap_rays(t_game *game);
void			draw_mini_square(t_game *game, int x, int y, int size);
void			draw_minimap(t_game *game);
void			draw_player(t_game *game);

// movement.c
void			handle_movement(t_game *game);
int				movement_delta(t_game *game, double *x, double *y);
int				is_wall(t_game *game, double x, double y);
int				can_move(t_game *game, double x, double y);
void			player_move(t_game *game, double x, double y);

// render.c
void			draw_floor_ceiling(t_game *game);
void			resize_call(int width, int height, void *data);
void			render(t_game *game);

// rotation.c
void			handle_rotation(t_game *game);
void			handle_mouse_rotation(t_game *game);

// textures.c
uint32_t		get_texture_color(mlx_texture_t *texture, int x, int y);
mlx_texture_t	*get_texture(t_game *game);
void			draw_wall_texture(t_game *game, int x);

// walls.c
void			compute_hit(t_game *game, double angle, t_dda *dda);
void			calculate_ray(t_game *game, double ray);
void			draw_wall_tile(t_game *game, double ray, int x);
void			draw_walls(t_game *game);

#endif
