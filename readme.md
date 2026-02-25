
Files
====================
Turn in files 

• Makefile all, clean, fclean, re, bonus

• Arguments a map in format *.cub

Allowed functions
====================
• open, close, read, write,
printf, malloc, free, perror,
strerror, exit, gettimeofday.

• All functions of the math
library (-lm man man 3 math).

• gettimeofday()

• All functions of the MinilibX
library.

Scope
====================
• 4 textures

• 2 colours (requires rgb/hex conversion)

• minimap?

• Map size limit? 200? 300?

• restrict args to exact file name?


Variables
====================
• user arg (map name .cub)

• Texture paths

• map dimensions

• floor/ceiling colours


Data structs
====================
• linked list for temp grid

• 2d array for grid

Mem allocs
====================
• structs?

• linked list for grid map

To do
====================
- floodfill
- player spawn and direction

Traps
====================
DDA algo, ray calculation
- double paths on single line
- spaces and tabs in texture/metadata line in map
