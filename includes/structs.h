#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_game
{
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
}				t_game;
typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			floor_col;
	int			sky_col;
}				t_map;

typedef struct s_texture
{
}				t_texture;

typedef struct s_player
{
} t_player

#endif