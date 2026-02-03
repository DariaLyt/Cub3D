#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_status
{
	SUCCESS = 0, // success always 0 or if checks will fail!
	INVALID = 1,
	VALID = 2,
	ALLOC_FAIL = 3,
	CONTINUE = 4
}			t_status;

typedef struct s_map
{
	t_list	*temp_list;
	char	**grid;
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_col;
	int		ceiling_col;
}			t_map;

typedef struct s_texture
{
}			t_texture;

typedef struct s_player
{
}			t_player;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	// struct s_texture	*texture;
	// struct s_player		*player;
}			t_game;

#endif