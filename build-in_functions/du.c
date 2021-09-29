//
// Created by Сергей Шакотько on 29.09.2021.
//

#include <dirent.h>
#include <MacTypes.h>
#include <stdio.h>
#include <sys/stat.h>

int du() {
    DIR *dir;
    struct dirent *ent;
    struct stat file_stat;

    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (!stat(ent->d_name, &file_stat)) {
                printf("%lld\t", file_stat.st_size);
            }
            printf("%s\n", ent->d_name);
        }
        closedir(dir);

        return 0;
    }

    perror("failed");

    return 1;
}
