#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_col;
	int				ceiling_col;
}					t_map;

typedef struct s_texture
{
}					t_texture;

typedef struct s_player
{
}					t_player;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	// struct s_texture	*texture;
	// struct s_player		*player;
}					t_game;

enum				e_status
{
	SUCCESS = 0,
	INVALID = 1,
	VALID = 2,
	WHY = 3,
	CONTINUE = 4
};

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

#endif