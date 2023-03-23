Sources
# https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
# https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
# https://www.youtube.com/watch?v=p4Iz0XJY-Qk

# Tutorials:
# https://www.google.com/search?q=draw+line+in+fdf+42&oq=draw+line+in+fdf+42&aqs=chrome..69i57j69i60.4140j0j7&sourceid=chrome&ie=UTF-8#fpstate=ive&vld=cid:3df5072b,vid:10P59aOgi68

Compile on MacOS
gcc -I<minilibx dir> <src/*.c> -L<minilibx dir> -lmlx -framework OpenGL -framework AppKit

ex.
gcc -Iminilibx_macos src/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework ApptKit

method 2:
gcc src/main.c -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
