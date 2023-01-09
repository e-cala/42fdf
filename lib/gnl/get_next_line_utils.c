/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:46:20 by ecabanas          #+#    #+#             */
/*   Updated: 2022/08/25 09:28:48 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_newline(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	ptr = calloc(i + j +1, sizeof * ptr);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	return (ptr);
}

char	*ft_strdup(char	*s)
{
	char	*ptr;
	int		i;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	while (s[i])
		i++;
	ptr = calloc(i + 1, sizeof * ptr);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_free(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (count--)
		ptr[count] = '\0';
	return (ptr);
}
