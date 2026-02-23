#include "cub.h"

int is_map_closed(t_game *game)
{
	char **temp_grid;
	int is_closed;

	temp_grid = ft_dup_map(game);

	if(find_player(game) == INVALID)
	{
		free_tmp_map(temp_grid);
		return(printf("rip bad map, not enclosed\n"), INVALID);
	}		

	if(flood_fill(game, temp_grid, game->player.x, game->player.y) == INVALID)
	{
		free_tmp_map(temp_grid);
		return(printf("rip bad map, not enclosed\n"), INVALID);
	}
	free_tmp_map(temp_grid);
	return(SUCCESS);
}

int find_player(t_game *game)
{
    int x;
    int y = 0;
    int count = 0;

    while(game->map.grid[y])
    {
        x = 0;
        while(game->map.grid[y][x])
        {
            if(ft_strchr("NSEW", game->map.grid[y][x]))
            {
                save_play_cord(game, game->map.grid[y][x], x, y);
                count++;
            }
            x++;
        }
        y++;
    }
    if (count != 1)
    {
        printf("Error\nMap must have exactly one player (found %d)\n", count);
		return(INVALID);
    }
	return(SUCCESS);
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
    char **temp_grid;
    
    temp_grid = malloc(sizeof(char *) * (game->map.height + 1));
    if(!temp_grid)
        return(NULL);

    while(y < game->map.height)
    {
        temp_grid[y] = ft_strdup(game->map.grid[y]);
        if(!temp_grid[y])
        {
            while (--y >= 0)
                free(temp_grid[y]);
            free(temp_grid);
            return(NULL);
        }
        y++;
    }
    temp_grid[y] = NULL;
    return(temp_grid);
}

int flood_fill(t_game *game, char **temp_grid, int x, int y)
{
    // 1. OUT OF BOUNDS = LEAK
    if (y < 0 || y >= game->map.height || x < 0 || x >= (int)ft_strlen(temp_grid[y]))
        return (INVALID);

    // 2. SPACE = LEAK
    if (temp_grid[y][x] == ' ' || temp_grid[y][x] == '\t' || temp_grid[y][x] == '\n')
        return (INVALID);

    // 3. WALL OR ALREADY VISITED = SAFE
    if (temp_grid[y][x] == '1' || temp_grid[y][x] == 'V')
        return (SUCCESS);

    // 4. MARK AS VISITED
    temp_grid[y][x] = 'V';

    // 5. RECURSE: If ANY direction finds an INVALID path, this whole path is INVALID
    if (flood_fill(game, temp_grid, x + 1, y) == INVALID) return (INVALID);
    if (flood_fill(game, temp_grid, x - 1, y) == INVALID) return (INVALID);
    if (flood_fill(game, temp_grid, x, y + 1) == INVALID) return (INVALID);
    if (flood_fill(game, temp_grid, x, y - 1) == INVALID) return (INVALID);

    return (SUCCESS);
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
