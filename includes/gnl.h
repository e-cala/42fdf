/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecabanas <ecabanas@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:38:26 by ecabanas          #+#    #+#             */
/*   Updated: 2023/04/29 10:39:06 by ecabanas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>	//read() function
# include <fcntl.h>  //open() function
# include "../lib/libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*      gnl.c           */
char	*get_next_line(int fd);

/*      gnl_utils.c     */
int		ft_found_newline(char *s);
void	ft_free(char **s1, char **s2, char **s3);
void	*ft_calloc(size_t count, size_t size);

/*      errors.c        */
void    err(char *str);

#endif
