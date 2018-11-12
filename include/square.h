/*
** EPITECH PROJECT, 2018
** square_header
** File description:
** square_header
*/

#ifndef SQUARE_H
#define SQUARE_H

typedef struct square_s {
    int x;
    int y;
    int size;
} square_t;

square_t *create_square(int x, int y, int size);
void copy_square_props(square_t *src, square_t *dest);
int get_pos(int x, int y, int w);

#endif // SQUARE_H
