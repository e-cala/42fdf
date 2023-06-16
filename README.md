# FdF
In this project we have to create a program that accepts a text file filled with a numerical table and must represent represent each of the points as a **3D object**. Each of the pixels must be linked to one another. 

## Controls
|KEY            |ACTION                       |
|---------------|-----------------------------|
|`Arrows`       |X/Y axis Rotation            |
|`i`            |ISOMETRIC view               |
|`ESC`			| Exit Program				  |	


## Steps

All your files and folders are presented as a tree in the file explorer. You can switch from one to another by clicking a file in the tree.
1. Printing pixels on screen 1 by 1.
	> `my_mlx_pixel_put(t_data *data, int  x, int  y, int  color)`
	
2. Printing 1 line between 2 pixels.
	> `plot_line_high(t_meta *meta, t_point start, t_point end)`

3.  Printing all of the points from a file
	> `draw_points(t_meta *meta, t_point *copy_points)`

4. Printing the whole Grid
	> `draw_map(t_meta *meta)`

## Compiling project on MacOS
```bash
$ gcc -I<minilibx dir> <src/*.c> -L<minilibx dir> -lmlx -framework OpenGL -framework AppKit
```
**Examples**

**Method 1**
```bash
$ gcc -Iminilibx_macos src/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework ApptKit
```
**Method 2**
```bash
$ gcc src/main.c -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
```

## Sources
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
- https://www.youtube.com/watch?v=p4Iz0XJY-Qk
- https://en.wikipedia.org/wiki/Bresenham's_line_algorithm#All_cases
- https://github.dev/albagg3/42_FdF/tree/main

## Tutorials:
- https://www.google.com/search?q=draw+line+in+fdf+42&oq=draw+line+in+fdf+42&aqs=chrome..69i57j69i60.4140j0j7&sourceid=chrome&ie=UTF-8#fpstate=ive&vld=cid:3df5072b,vid:10P59aOgi68