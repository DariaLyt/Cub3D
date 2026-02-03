#ifndef STRUCTS_H
#define STRUCTS_H

# include "cub.h"

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	speed;
}	t_player;

typedef struct s_wall
{
	int	original_start;
	int original_end;
	int visible_start;
	int	visible_end;
	int	height;
} t_wall;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef	struct s_ray
{
	double	distance;
	double	dir_x;
	double	dir_y;
	double	hit_x;
	double	hit_y;
}	t_ray;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_ray	ray;

	int width;
	int height;
	t_map	map;
	t_player player;
	t_wall wall;
	uint32_t	ceiling;
	uint32_t	floor;
	bool 	player_moving;
	bool	game_running;
}	t_game;

#endif
