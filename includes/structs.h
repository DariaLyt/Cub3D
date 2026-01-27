#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_game
// {
// 	struct s_map		*map;
// 	struct s_texture	*texture;
// 	struct s_player		*player;
// }						t_game;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_col;
	int		sky_col;
}			t_map;

#endif