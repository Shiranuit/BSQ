/*
** EPITECH PROJECT, 2018
** square
** File description:
** square
*/

#include "square.h"
#include <stdlib.h>

square_t *create_square(int x, int y, int size)
{
    square_t *sq = malloc(sizeof(square_t));

    sq->x = x;
    sq->y = y;
    sq->size = size;
    return (sq);
}

int get_pos(int x, int y, int w)
{
    return (x + y * w);
}

void copy_square_props(square_t *src, square_t *dest)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->size = src->size;
}
