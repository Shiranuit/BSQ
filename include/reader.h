/*
** EPITECH PROJECT, 2018
** reader_header
** File description:
** reader_header
*/

#ifndef READER_H
#define READER_H

typedef struct filedata_s {
    char *origin;
    char *buf;
    int len;
    int lines;
    int columns;
} filedata_t;


filedata_t *readfile(char *filename);

#endif // READER_H
