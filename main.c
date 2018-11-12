/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "reader.h"
#include "square.h"
#include "bsq.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_data(filedata_t *file, square_t *sq)
{
    for (int y = sq->y; y < sq->y + sq->size; y++)
        for (int x = sq->x; x < sq->x + sq->size; x++)
            file->buf[x + y * (file->columns + 1)] = 'x';
    write(1, file->buf, file->len);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        filedata_t *file = readfile(av[1]);
        square_t *sq = check_biggest_square(file);
        print_data(file, sq);
        free(sq);
        free(file->origin);
        free(file);
    }
    return (0);
}
