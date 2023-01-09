Compile on MacOS
gcc -I<minilibx dir> <src/*.c> -L<minilibx dir> -lmlx -framework OpenGL -framework AppKit

ex.
gcc -Iminilibx_macos src/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework ApptKit
