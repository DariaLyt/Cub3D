#include "cub.h"

int	run_game(char *map_name, t_game *game)
{
	// game = malloc(sizeof(t_game));
	// if (!game)
		// return (0);
	init_game_struct(game);
	if(parsing(map_name, game) == INVALID)
		return(INVALID); // error and cleanup
	print_game_data(game); // << debug print // delete me when done
	// execution();
	free_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2 && argv[1][0])
		run_game(argv[1], &game);
	else
		printf("doofus");
	return (0);
}
