#include "../includes/gnl.h"
#include "../includes/fdf.h"
#include "../includes/errors.h"


int	count_elems_line(char **split)
{
	int	i;

	i = 0;
	while (split[i] && split[i][0] != '\0')
		i++;
	if (i == 0 || (i == 1 && split[0][0] == '\n'))
		err(ERR_EMPTY);
	//printf("elems: %i ", i);
	return (i);
}

void	map_init(t_map	*map)
{
	map->total_size = 0;
}

void	valid_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**splitted;
	int		max_x;

	(void)max_x;
	(void)map;
	fd = open(filename, O_RDONLY);
	if (fd < 2)
		err(ERR_NOMAP);
	line = get_next_line(fd);
	while (line)
	{
		splitted = ft_split(line, ' ');
		max_x = count_elems_line(splitted);
		free_double_pointer(splitted);
		/*
		ifs...
		*/
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	read_file(char *filename, t_map *map)
{
	//int		line_number;
	int		fd;
	char	*line;

	//line_number = 0;
	map_init(map);
	valid_map(filename, map);
	map->points = ft_calloc(map->total_size, sizeof * map->points);
	fd = open(filename, O_RDONLY);
	if (fd < 2 || !map->points)
		return (0);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;	
		printf("%s", line);
		free(line);
		//line_number++;
	}
	free(map->points);
	return (1);
}