Sources
# https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
# https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
# https://www.youtube.com/watch?v=p4Iz0XJY-Qk

Compile on MacOS
gcc -I<minilibx dir> <src/*.c> -L<minilibx dir> -lmlx -framework OpenGL -framework AppKit

ex.
gcc -Iminilibx_macos src/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework ApptKit

method 2:
gcc src/main.c -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
