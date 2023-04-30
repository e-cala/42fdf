#include "../includes/gnl.h"
#include "../includes/fdf.h"

int	read_file(char *filename, t_map *map)
{
	int		line_number;
	int		fd;
	char	*line;

	line_number = 0;
	map->points = ft_calloc(0, sizeof * map->points);
	fd = open(filename, O_RDONLY);
	if (fd < 2 || map->points == NULL)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line_number++;
	}
	return (1);
}