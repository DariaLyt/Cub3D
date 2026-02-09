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

typedef struct s_wall
{
	int original_start;
	int original_end;
	int visible_start;
	int visble_end;
	int height;
}	t_wall;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	speed;
}			t_player;

typedef	struct s_ray
{
	double distance;
	double dir_x;
	double dir_y;
	double hit_x;
	double hit_y;
}	t_ray;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_t	*mlx;
	mlx_image_t	*image;
	t_ray	ray;
	int width;
	int height;
	t_player player;
	t_wall wall;
	uint32_t	ceiling;
	uint32_t	floor;
	uint32_t	mini_color;
	bool 	player_moving;
	bool	game_running;


	t_map	map;
	// struct s_texture	*texture;
	// struct s_player		*player;
}			t_game;

#endif