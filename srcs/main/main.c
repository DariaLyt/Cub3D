#include "cub.h"

int	run_game(char *map_name, t_game *game)
{
	parsing(map_name, game);
	print_game_data(game); // << debug print // delete when done
	// execution();
	return(0);
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
