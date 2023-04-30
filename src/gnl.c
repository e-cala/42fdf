/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:40:00 by ecabanas          #+#    #+#             */
/*   Updated: 2023/04/29 10:40:05 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/gnl.h"

// IMPORTANTE QUE SEA FT_CALLOC (errores con calloc)
static char	*get_before_newline(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	ptr = ft_calloc(i + 1, sizeof * ptr);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// IMPORTANTE QUE SEA FT_CALLOC o CALLOC (errores con malloc)
static char	*get_after_newline(char *s)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	ptr = ft_calloc((j - i) + 1, sizeof * ptr);
	if (!ptr)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		ptr[j] = s[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

// NO NECESARIO FT_CALLOC, MALLOC FUNCIONA TMB
static void	ft_read_line(int fd, char **storage, char **tmp)
{
	char	*buf;
	int		r;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof * buf);
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free(&buf, storage, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*storage);
		ft_free(storage, 0, 0);
		*storage = ft_strjoin(*tmp, buf);
		ft_free(tmp, 0, 0);
		if (ft_found_newline(*storage))
			break ;
	}
	ft_free(&buf, 0, 0);
}

static char	*ft_parse_line(char **storage, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*storage);
	ft_free(storage, 0, 0);
	*storage = get_after_newline(*tmp);
	line = get_before_newline(*tmp);
	ft_free(tmp, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = NULL;
	line = NULL;
	ft_read_line(fd, &storage, &tmp);
	if (storage != NULL && *storage != '\0')
		line = ft_parse_line(&storage, &tmp);
	if (!line || *line == '\0')
	{	
		ft_free(&storage, &tmp, &line);
		return (NULL);
	}
	return (line);
}
