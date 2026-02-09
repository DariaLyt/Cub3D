#include "cub.h"

	// Currently not used
int is_xpm(char *path)
{
    int len;

    len = ft_strlen(path);
    if (len < 5)
        return (0);
    if (ft_strncmp(path + len - 4, ".xpm", 4) == 0)
        return (1);
    return (0);
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
            return (0);
		i++;
	}
	if(i > 0)
		return 1;
	return 0;
}

int	is_valid_map_line(char *line)
{
	while (*line)
	{
		if (is_valid_char(*line) == INVALID)
			return (INVALID);
		line++;
	}
	return (SUCCESS);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == '\n' || c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (SUCCESS);
	return (INVALID);
}
