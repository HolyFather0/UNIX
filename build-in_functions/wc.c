//
// Created by Сергей Шакотько on 14.09.2021.
//

#include <unistd.h>
#include <ctype.h>
#include <printf.h>
#include <sys/fcntl.h>

void analyzeFd(int fd) {
    char buf;
    ssize_t readed = 0;
    int words = 0;
    int lines = 0;
    int bytes = 0;

    int isNewWord = 0;
    while ((readed = read(fd, &buf, 1)) > 0) {

        if (isspace(buf)) {
            if (isNewWord) {
                words++;
                isNewWord = 0;
            }
            if (buf == '\n') {
                lines++;
            }
        } else {
            isNewWord = 1;
        }
        bytes++;
    }
    printf("\b\b  \b\b\t%d\t%d\t%d\n", lines, words, bytes);
}

int wc(int argc, char **argv) {
    write(1, "\n", 1);
    if (argc == 0) {
        analyzeFd(0);
    } else {
        int fd = open(argv[0], O_RDONLY);
        if (fd < 0) {
            perror("No such file or directory");
            return 1;
        }
        analyzeFd(fd);
        close(fd);
    }

    return 0;
}