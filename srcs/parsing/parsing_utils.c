#include "cub.h"

char	*ft_strjoin_and_free(char *map_whole, char *line)
{
	char	*result;

	result = ft_strjoin(map_whole, line);
	if (map_whole)
		free(map_whole);
	if (line)
		free(line);
	return (result);
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (game->map.grid[i])
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
	free(game->map.no_path);
	free(game->map.so_path);
	free(game->map.ea_path);
	free(game->map.we_path);
	free_texture(game);
	if (game->map.temp_list)
		ft_lstclear(&game->map.temp_list, free);
}

char	*skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

void	free_texture(t_game *game)
{
	if (game->texture.north)
		mlx_delete_texture(game->texture.north);
	if (game->texture.east)
		mlx_delete_texture(game->texture.east);
	if (game->texture.south)
		mlx_delete_texture(game->texture.south);
	if (game->texture.west)
		mlx_delete_texture(game->texture.west);
}
