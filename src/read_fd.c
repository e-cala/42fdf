#include "../includes/gnl.h"
#include "../includes/fdf.h"
#include "../includes/errors.h"


int	count_elems_line(char **split)
{
	int	i;

	i = 0;
	while (split[i] && split[i][0] != '\n')
		i++;
	if (i == 0 || (i == 1 && split[0][0] == '\n'))
		err(ERR_EMPTY);
	return (i);
}

void	map_init(t_map	*map)
{
	map->total_size = 0;
	map->limits.axis[X] = 0;
	map->limits.axis[Y] = 0;
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->len = 0;
	map->source.axis[X] = WIN_WIDTH / 2;
	map->source.axis[Y] = WIN_HEIGHT / 2;
	map->source.axis[Z] = 0;
	map->divisor = 1;
	map->scale = 1;
}

void	ft_load_color(t_map *map, char *line)
{
	char	**color;
	
	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		map->points[map->len].color = (long)strtol(color[1] + 2, NULL, 16);
		free_double_pointer(color);
	}
	else
		map->points[map->len].color = YELLOW;
}

void	valid_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		max_x;

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		err(ERR_NOMAP);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		max_x = count_elems_line(split);
		if (map->limits.axis[X] == 0)
			map->limits.axis[X] = max_x;
		if (map->limits.axis[X] != max_x)
			err(ERR_MAP);
		free(line);
		free_double_pointer(split);
		line = get_next_line(fd);
		map->total_size += max_x;
		map->limits.axis[Y]++;
	}
	close(fd);
}

void	save_map_points(t_map *map, int	line_num, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] && split[i][0] != '\n')
	{
		//TODO:	HARDCODED VALUES x30 PARA SEPARAR LOS PUNTOS --> FIX 
		map->points[map->len].axis[X] = 30 * (i - map->limits.axis[X] / 2);
		map->points[map->len].axis[Y] = 30 * (line_num - map->limits.axis[Y] / 2);
		if (!ft_isdigit(split[i][0]) && split[i][0] != '-')
			err(ERR_MAP);
		map->points[map->len].axis[Z] = ft_atoi(split[i]);
		ft_load_color(map, split[i]);
		i++;
		map->len++;
	}
	free_double_pointer(split);
}

int	read_file(char *filename, t_map *map)
{
	int		fd;
	int		line_num;
	char	*line;

	map_init(map);
	valid_map(filename, map);
	map->points = ft_calloc(map->total_size, sizeof * map->points);
	line_num = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 2 || !map->points)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		save_map_points(map, line_num, line);
		line_num++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
