#include "cub.h"

int is_valid_ext(char *map_name)
{
    size_t len;

    if (!map_name)
        return (INVALID);
    len = ft_strlen(map_name);
    if (len < 5 || ft_strncmp(&map_name[len - 4], ".cub", 4) != 0)
        return (printf("Error: Invalid file extension\n"), INVALID);
    return (SUCCESS);
}

int parse_line(t_game *game, char *line)
{
    char    *trimmed;

    trimmed = skip_spaces(line);
    if (*trimmed == '\0')
    {
        if (game->map.temp_list != NULL)
            return (printf("Error: Empty line inside map\n"), INVALID);
        return (SUCCESS);
    }
    if (game->map.meta_count < 6)
    {
        if (is_metadata(game, line) == SUCCESS)
        {
            game->map.meta_count++;
            return (SUCCESS);
        }
		printf("Error: Missing metadata or invalid identifier\n");
        return (INVALID);
    }
    add_to_map_list(game, line);
    return (SUCCESS);
}

int parse_file(t_game *game, int fd)
{
    char    *line;
    int     status;
	status = SUCCESS;

    game->map.meta_count = 0;
    while ((line = get_next_line(fd)))
    {
        status = parse_line(game, line);
		free(line);
        if (status == INVALID)
		{
			while ((line = get_next_line(fd)))
				free(line);
            return (INVALID);
		}
    }
    if (game->map.meta_count != 6)
        return (printf("Error: Metadata missing\n"), INVALID);
    if (!game->map.temp_list)
        return (printf("Error: Map missing\n"), INVALID);
    return (SUCCESS);
}

/*

check for anything besides metadata when count < 6
check for duplicates


TESTS REQUIRED!
- test multiple meta
- test for garbage on rgb meta data or extra characters
- test 
*/