#ifndef CUB_H
# define CUB_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "structs.h"
#include "libft.h"


# define MIN_WIDTH 384
# define MIN_HEIGHT 216
# define MINIMAP_SCALE 0.15
# define TILE_SIZE 64
# define STEP_SIZE 0.5

// Parsing

// Execution

// Error & Cleanup

// Utils

// library?

//execution

int init_game(t_game *game);

// movement
void    handle_movement(t_game *game);
int movement_delta(t_game *game, double *x, double *y);

// rotation

//render
void    render(t_game *game);

#endif