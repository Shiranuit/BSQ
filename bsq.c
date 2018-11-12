/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

#include "reader.h"
#include "square.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int min(int a, int b)
{
    return (a < b ? a : b);
}

int get(int x, int y, filedata_t *data, int *lst)
{
    if (x < 0 || x > data->columns - 1)
        return (0);
    if (y < 0 || y > data->lines - 1)
        return (0);
    return (lst[get_pos(x, y, data->columns)]);
}

int get_min(int x, int y, filedata_t *data, int *lst)
{
    int val = min(get(x + 1, y, data, lst), get(x, y + 1, data, lst));

    val = min(val, get(x + 1, y + 1, data, lst));
    return (val + 1);
}

void update_max(square_t *sq, square_t *big)
{
    if (sq->size > big->size)
        copy_square_props(sq, big);
    else if (sq->size == big->size)
        if (sq->x < big->x || sq->y < big->y)
            copy_square_props(sq, big);
}

square_t *check_biggest_square(filedata_t *fdata)
{
    square_t *big = create_square(0, 0, 0);
    square_t *this = create_square(0, 0, 0);
    int *lst = malloc(sizeof(int) * (fdata->len - fdata->lines));
    int pos = 0;

    for (int i, j = 0; i < fdata->len; i++)
        if (fdata->buf[i] != '\n')
            lst[j++] = fdata->buf[i] == '.' ? 1 : 0;
    for (int y = fdata->lines - 1; y > -1; y--)
        for (int x = fdata->columns - 1; x > -1; x--) {
            pos = get_pos(x, y, fdata->columns);
            lst[pos] = lst[pos] == 1 ? get_min(x, y, fdata, lst) : 0;
            this->x = x;
            this->y = y;
            this->size = lst[pos];
            update_max(this, big);
        }
    free(this);
    free(lst);
    return (big);
}
