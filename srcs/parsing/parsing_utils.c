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
}

int is_space(char c)
{
	int i = 0;

	if(c == ' ' || (c >= 9 && c <= 13))
		return 1;
	else 
		return 0;
}

int is_empty_line(char *str)
{
	int i = 0;

	while(str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
            return (SUCCESS);
		i++;
	}
	if(i > 0)
		return INVALID;
	return SUCCESS;
}

char *skip_spaces(char *str)
{
	if(!str)
		return (NULL);
	while(*str == ' ' || *str == '\t')
			str++;
	return(str);
}
