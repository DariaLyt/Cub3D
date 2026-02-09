#include "cub.h"

int    init_test_map(t_game *game)
{
    game->map.grid = ft_calloc(7, sizeof (char *));
    if (!game->map.grid)
    {
        ft_printf("Malloc failed\n");
        return (0);
    }
    game->map.height = 6;
    game->map.grid[0] = ft_strdup("1111111111111111111111");
    game->map.grid[1] = ft_strdup("1000000000000000000001");
    game->map.grid[2] = ft_strdup("1010010100100000101001");
    game->map.grid[3] = ft_strdup("1010010010101010001001");
    game->map.grid[4] = ft_strdup("1000000000000000000001");
    game->map.grid[5] = ft_strdup("1111111111111111111111");
    return (1);
}

int init_mlx(t_game *game)
{
    int monitor_width;
    int monitor_height;
    game->mlx = mlx_init(MIN_WIDTH, MIN_HEIGHT, "Cub3D", true);
    if (!game->mlx)
    {
        ft_putstr_fd("Failed to initialize mlx", 1);
        return (0);
    }
    mlx_get_monitor_size(0, &monitor_width, &monitor_height);
    game->width = monitor_width / 2;
    game->height = monitor_height / 2;
    ft_printf("width - %d\nheight - %d\n", game->width, game->height);
    mlx_set_window_size(game->mlx, game->width, game->height);
    mlx_set_window_limit(game->mlx, MIN_WIDTH, MIN_HEIGHT, monitor_width, monitor_height);
    return (1);
}

int init_game(t_game *game)
{
    //init_test_map(game);
    game->player.speed = 0.025;
    game->player.angle = 0; // <- based on N S W E
    game->floor = BLACK_COLOR; // turned rgb in int (need to make function for this);
    game->ceiling = WHITE_COLOR;
    if (!init_mlx(game))
        return (0);
    int i = 0;
    // while (i < game->map.height)
    // {
    //     ft_printf("%s\n", game->map.grid[i]);
    //     i++;
    // }
    game->image = mlx_new_image(game->mlx, game->width, game->width);
    if (!game->image)
    {
        ft_printf("Failed mlx image\n");
        return (0);
    }
    return (1);
}
