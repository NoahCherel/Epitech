/*
** EPITECH PROJECT, 2022
** UTILS
** File description:
** Useful functions, usually in lib
*/

#include "rpg.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

char *my_inttostr(int num)
{
    int len = 0; if (num == 0) len++;
    for (int k = num; k != 0; k = k / 10, len++);
    char *p = malloc(sizeof(char) * (len + 1));
    p[len] = '\0'; len--;
    for (; len >= 0; len--) {
        p[len] = num % 10 + 48;
        num /= 10;
    }
    return (p);
}

int my_strlen(char const *str)
{
    int count = 0;
    for (count = 0; str[count] != '\0'; count++);
    return (count);
}

int get_file_size(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    int size = 0;
    char c;
    while (read(fd, &c, 1) > 0) {
        size++;
    }
    close(fd);
    return (size);
}

char *get_content_of_file(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) return (NULL);
    int size = get_file_size(file_name);
    if (size < 1) return (NULL);
    char *buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL) return (NULL);
    int read_bytes = read(fd, buffer, size);
    if (read_bytes != size) return (NULL);
    buffer[read_bytes] = '\0';
    return (buffer);
}
