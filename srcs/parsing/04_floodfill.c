#include "cub.h"

int is_map_closed(t_game *game)
{
	char **temp_grid;
	int is_closed;

	temp_grid = ft_dup_map(game);

	find_player(game);

	if(flood_fill(game, temp_grid, game->player.x, game->player.y) == INVALID)
	{
		free_tmp_map(temp_grid);
		return(printf("rip bad map, not enclosed\n"), INVALID);
	}
	free_tmp_map(temp_grid);
	return(SUCCESS);
}

void find_player(t_game *game)
{
	int x;
	int y = 0;
	while(game->map.grid[y])
	{
		x = 0;
		while(game->map.grid[y][x])
		{
			if(game->map.grid[y][x] == 'N')
				save_play_cord(game, "N", x, y);
			if(game->map.grid[y][x] == 'E')
				save_play_cord(game, "E", x, y);
			if(game->map.grid[y][x] == 'S') 
				save_play_cord(game, "S", x, y);
			if(game->map.grid[y][x] == 'W') 
				save_play_cord(game, "W", x, y);
			x++;
		}
		y++;
	}
}

void save_play_cord(t_game *game, char direction, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->player.direction = direction;
}

char **ft_dup_map(t_game *game)
{
	int y = 0;
	int x;
	char **temp_grid;
	
	temp_grid = malloc(sizeof(char *) * (game->map.height + 1));
	if(!temp_grid)
		return(NULL);

	while(game->map.grid[y])
	{
		temp_grid[y] = malloc(sizeof(char) * (ft_strlen(game->map.grid[y]) + 1));
		if(!temp_grid)
			return(NULL);
		
		x = 0;
		while(game->map.grid[y][x])
		{
			temp_grid[y][x] = game->map.grid[y][x];
			x++;
		}
		temp_grid[y][x] = '\0';
		y++;
	}
	temp_grid[y] = NULL;
	return(temp_grid);
}

int flood_fill(t_game *game, char **temp_grid, int x, int y)
{
	if (y < 0 || y >= game->map.height || x < 0 || x >= (int)ft_strlen(temp_grid[y]))
		return (INVALID);

	if (temp_grid[y][x] == ' ' || temp_grid[y][x] == '\t')
		return (INVALID);

	if (temp_grid[y][x] == '1' || temp_grid[y][x] == 'V')
		return (SUCCESS);

	temp_grid[y][x] = 'V';

	if (!flood_fill(game, temp_grid, x + 1, y)) return (INVALID);
	if (!flood_fill(game, temp_grid, x - 1, y)) return (INVALID);
	if (!flood_fill(game, temp_grid, x, y + 1)) return (INVALID);
	if (!flood_fill(game, temp_grid, x, y - 1)) return (INVALID);

	return (1);
}

void free_tmp_map(char **map)
{
	int i = 0;

	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
