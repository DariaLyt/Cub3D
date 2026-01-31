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
 
void free_map(t_game *game)
{
	int i;

	if(game->map.grid)
	{
		i = 0;

		while(game->map.grid[i])
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
	free(game->map.floor_col);
	free(game->map.ceiling_col);
}

int is_space(char c)
{
	int i = 0;

	if(c = ' ')
		return 1;
	else 
		return 0;
}

int is_empty_line(char *str)
{
	int i = 0;

	while(str[i])
	{
		i++;
	}
	if(i > 0)
		return 1;
	return 0;
}

char *skip_spaces(char *str)
{
	while(*str)
	{
		if(*str == ' ' || '\t')
			str++;
	}
	return(str);
}
