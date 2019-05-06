#include "fillit.h"

void    clear_solution_board(t_board *main_board)
{
    int i;

    i = 0;
    if (main_board)
    {
        while (main_board->solved_board[i])
        {
            ft_bzero(main_board->solved_board[i], (size_t)ft_strlen(main_board->solved_board[i]));
            free(main_board->solved_board[i]);
            main_board->solved_board[i] = NULL;
            i++;
        }
        free(main_board->solved_board);
    }
}

/*
** Generates a new solution baord of 'size' width and height
*/

int     start_size(int square)
{
    int ret;

    ret = 0;
    while (((ret * ret)/square) < 1)
    {
        ret++;
    }
    if (((ret * ret)/square) > 1)
        return (ret - 1);
    return (ret);
}

void    generate_solution_board(t_board *main_board, int size)
{
    char    *tmp;
    char    *line;
    int     i;

    i = 0;
    line = ft_strnew(1);
    ft_bzero(line, 1);
    if (main_board && size >= 1)
    {
        main_board->solved_board = (char **)malloc(sizeof(char *) * (size + 1));
        while (i++ < size)
        {
            tmp = ft_strnew((size_t)(size + 1));
            ft_memset(tmp, '.', (size_t)size);
            tmp[size] = 'Z';
            line = ft_strjoin(line, tmp);
            free(tmp);
            ft_bzero(tmp, (size_t)size);
        }
        main_board->solved_board = ft_strsplit(line, 'Z');
    }
}