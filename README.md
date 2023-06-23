# FdF
In this project we have to create a program that accepts a text file filled with a numerical table and must represent represent each of the points as a **3D object**. Each of the pixels must be linked to one another. 

## Controls
|KEY            |ACTION                       |
|---------------|-----------------------------|
|`Arrows`       |X/Y axis Rotation            |
|`i`            |ISOMETRIC view               |
|`ESC`			| Exit Program				  |	


## Steps

This is the sequence of problems that has been addressed to solve the project.
1. Printing pixels on screen 1 by 1.
	> `my_mlx_pixel_put(t_data *data, int  x, int  y, int  color)`
	
2. Printing 1 line between 2 pixels.
	> `plot_line(t_meta *meta, t_point start, t_point end)`

3.  Printing all of the points from a file
	> `draw_points(t_meta *meta, t_point *copy_points)`

4. Printing the whole Grid
	> `draw_map(t_meta *meta)`

## Compiling project on MacOS
```bash
$ gcc -I<minilibx dir> <src/*.c> -L<minilibx dir> -lmlx -framework OpenGL -framework AppKit
```
### Examples

##### Method 1
```bash
$ gcc -Iminilibx_macos src/main.c -Lminilibx_macos -lmlx -framework OpenGL -framework ApptKit
```
##### Method 2
```bash
$ gcc src/main.c -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
```

## Sources
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
- https://www.youtube.com/watch?v=p4Iz0XJY-Qk
- https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
- [GDB Tutorial](http://www.unknownroad.com/rtfm/gdbtut/gdbtoc.html)

## Tutorials:
- [FdF walkthrough](https://www.youtube.com/watch?v=10P59aOgi68&t=256s&ab_channel=%D0%9D%D0%B8%D0%BA%D0%BE%D0%BB%D0%B0%D0%B9%D0%A1%D0%A4%D0%B0%D0%BC%D0%B8%D0%BB%D0%B8%D0%B5%D0%B9)