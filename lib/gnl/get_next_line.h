/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:46:03 by ecabanas          #+#    #+#             */
/*   Updated: 2022/08/25 09:29:15 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>	//read() function
# include <fcntl.h>  //open() function

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//	GET_NEXT_LINE.C	//
char	*get_next_line(int fd);
void	ft_read_line(int fd, char **storage, char **tmp);
char	*get_before_newline(char *s);
char	*get_after_newline(char *s);
char	*ft_parse_line(char **storage, char **tmp);

//	GET_NEXT_LINE_UTILS.C	//
int		ft_found_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
void	ft_free(char **s1, char **s2, char **s3);
void	*ft_calloc(size_t count, size_t size);

#endif
