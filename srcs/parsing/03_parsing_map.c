#include "cub.h"

int	add_to_map_list(t_game *game, char *line)
{
	t_list	*new_node;

	if (is_valid_map_line(line) == INVALID)
		return (INVALID);
	new_node = ft_lstnew(ft_strdup(line));
	if (!new_node)
		return (ALLOC_FAIL);
	ft_lstadd_back(&(game->map.temp_list), new_node);
	update_map_dims(&game->map, line);
	// << check here for Max map limit?
	return (SUCCESS);
}

void	update_map_dims(t_map *map, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len > map->width)
		map->width = len;
	map->height++;
}

int	convert_list_to_grid(t_game *game)
{
	t_list	*current;
	int		i;

	if (!game->map.temp_list)
		return (INVALID);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (ALLOC_FAIL);
	current = game->map.temp_list;
	i = 0;
	while (current)
	{
		game->map.grid[i] = ft_strdup(current->content);
		if (!game->map.grid[i])
			return (ALLOC_FAIL); // free?
		current = current->next;
		i++;
	}
	game->map.grid[i] = NULL;
	return (SUCCESS);
}
