/*
** EPITECH PROJECT, 2018
** reader
** File description:
** reader
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "reader.h"

int read_lines_count(filedata_t *fdata)
{
    int index = 0;
    int count = 0;

    while (fdata->buf[index] >= '0' && fdata->buf[index] <= '9') {
        count *= 10;
        count += fdata->buf[index] - '0';
        index++;
    }
    fdata->len -= index + 1;
    fdata->buf += index + 1;
    return (count);
}

int read_columns_count(filedata_t *fdata)
{
    int len = -1;

    while (fdata->buf[++len] != '\n');
    return (len);
}

filedata_t *readfile(char *filename)
{
    struct stat *stats = malloc(sizeof(struct stat));
    filedata_t *data = malloc(sizeof(filedata_t));
    int offset = 0;
    int rd = 0;
    int fd = open(filename, O_RDONLY);

    stat(filename, stats);
    data->len = stats->st_size;
    data->buf = malloc(sizeof(char) * data->len);
    while ((rd = read(fd, data->buf + offset, data->len - offset)) > 0)
        offset = rd;
    close(fd);
    data->origin = data->buf;
    data->lines = read_lines_count(data);
    data->columns = read_columns_count(data);
    free(stats);
    return (data);
}
