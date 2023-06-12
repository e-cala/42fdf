#include "../lib/libft/libft.h"


void    err(char *str)
{
    ft_putstr_fd("Error: ", 2);
    ft_putendl_fd(str, 1);
    exit(EXIT_FAILURE);
}

void    free_double_pointer(char **ptr)
{
    int i;

    if (!ptr)
        return ;
    i = 0;
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}

