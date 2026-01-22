#include "../include/cub3d.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error! Invalid number of arguments");
        return (1);
    }
    printf("%s\n", argv[1]);
    return (0);
}