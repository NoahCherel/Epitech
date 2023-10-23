/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ls_l
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void ls_l_total(char *file)
{
    struct dirent *de; struct stat st; int total = 0; DIR *dir = opendir(file);
    while ((de = readdir(dir)) != NULL)
        if (stat(my_strcat(file, de->d_name), &st) == 0) {
            (de->d_name[0] != '.' ) ? total += st.st_blocks : 0;
        }
        my_putstr("total");my_putchar(' '); my_put_nbr(total / 2);
        my_putchar('\n');
    while (de) closedir(dir);
}

void permissions(struct stat st)
{
    if (S_ISREG(st.st_mode)) my_putchar('-');
    if (S_ISDIR(st.st_mode)) my_putchar('d');
    if (S_ISCHR(st.st_mode)) my_putchar('c');
    if (S_ISBLK(st.st_mode)) my_putchar('b');
    if (S_ISFIFO(st.st_mode)) my_putchar('p');
    if (S_ISLNK(st.st_mode)) my_putchar('l');
    if (st.st_mode & S_IRUSR) { my_putstr("r"); } else my_putstr("-");
    if (st.st_mode & S_IWUSR) { my_putstr("w"); } else my_putstr("-");
    if (st.st_mode & S_IXUSR) { my_putstr("x"); } else my_putstr("-");
    if (st.st_mode & S_IRGRP) { my_putstr("r"); } else my_putstr("-");
    if (st.st_mode & S_IWGRP) { my_putstr("w"); } else my_putstr("-");
    if (st.st_mode & S_IXGRP) { my_putstr("x"); } else my_putstr("-");
    if (st.st_mode & S_IROTH) { my_putstr("r"); } else my_putstr("-");
    if (st.st_mode & S_IWOTH) { my_putstr("w"); } else my_putstr("-");
    if (st.st_mode & S_IXOTH) { my_putstr("x."); } else my_putstr("-.");
}

void time1(struct stat st)
{
    char *r = ctime(&st.st_mtime);
    r[my_strlen(r) - 9] = '\0'; char *d = r + 4; my_putstr(d);
}

int my_ls_l(char *file)
{
    struct dirent *de; struct stat st; struct passwd *pwd; struct stat n_link;
    struct group *gid; struct stat info; DIR *dir = opendir(file);
    stat(file, &st); ls_l_total(file);
    while (de = readdir(dir)) {
        if (de->d_name[0] != '.') {
            stat(my_strcat(file, de->d_name), &n_link);
            stat(my_strcat(file, de->d_name), &info);
            stat(my_strcat(file, de->d_name), &st); permissions(st);
            my_putchar(' '); my_put_nbr(n_link.st_nlink); my_putchar(' ');
            if ((pwd = getpwuid(st.st_uid)) != NULL) my_putstr(pwd->pw_name);
            my_putchar(' ');
            if ((gid = getgrgid(st.st_gid)) != NULL) my_putstr(gid->gr_name);
            my_putchar(' '); my_put_nbr(info.st_size); my_putchar(' ');
            time1(st); my_putchar(' '); my_putstr(de->d_name);
            my_putchar('\n');
        }
    }
    while (de) closedir(dir);
    return (0);
}

int my_ls_l_multiple(int ac, char **av)
{
    int a = 0;
    for (int j = 1; j != ac; j++) if (opendir(av[j]) != NULL) {a++;}
    for (int i = 2; i != ac; i++) {
        if (a == 1)  my_ls_l(av[i]);
        if (a > 1) {
            my_putstr(av[i]); my_putchar(':'); my_putchar('\n');
            my_ls_l(av[i]);
        }
        if (i != ac - 1) my_putchar('\n');
    }
    return (0);
}
