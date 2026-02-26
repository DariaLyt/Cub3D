#include "cub.h"

char	*find_file(char *map_name)
{
	char	*path_name;
	char	*extension;
	int		fd;

	extension = ".cub";
	path_name = ft_strnstr(map_name, extension, ft_strlen(map_name));
	fd = open(path_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	close(fd);
	return (path_name);
}

int	parse_file(t_game *game, int fd)
{
	char	*line;
	int		count;
	int		status;

	status = SUCCESS;
	count = 0;
	while ((line = get_next_line(fd)))
	{
		if (status == SUCCESS)
		{
			if (is_empty_line(line))
				;
			else if (count < 6)
			{
				if (is_metadata(game, line) == SUCCESS)
					count++;
				else
				{
					printf("Error: Invalid map\n");
					status = INVALID;
				}
			}
			else
				add_to_map_list(game, line);
		}
		free(line);
	}
	if (status == SUCCESS && count != 6)
	{
		printf("Metadata MISSING\n");
		return (INVALID);
	}
	return (status);
}
