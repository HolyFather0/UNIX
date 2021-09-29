//
// Created by Сергей Шакотько on 29.09.2021.
//

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

int chmod_build_in(int argc, char **argv) {
    if (argc == 0) {
        printf("usage: chmod [mode] file_name");

        return 0;
    }
    if (argc != 2) {
        ft_putstr_fd("minishell: chmod: wrong arguments", 2);

        return (1);
    }

    char *mode = argv[0];
    char *path = argv[1];

    long i = strtol(mode, 0, 8);
    if (chmod(path, i) < 0) {
        fprintf(stderr, "error in chmod: %s\n", strerror(errno));

        return 1;
    }

    return 0;
}