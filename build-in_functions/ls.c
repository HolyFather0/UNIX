//
// Created by Сергей Шакотько on 03.10.2021.
//

#include <stdio.h>
#include <exit.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

static const char * lookup[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void display_contents(char * name){
    struct stat sb;
    struct tm * t;
    char link_read[255];
    ssize_t bytes_read;
    lstat(name, &sb);

    printf("%c", S_ISDIR(sb.st_mode)?'d':\
		     S_ISFIFO(sb.st_mode)?'p':\
		     S_ISLNK(sb.st_mode)?'l':'-');


    printf("%c", (S_IRUSR & sb.st_mode) ? 'r' : '-');
    printf("%c", (S_IWUSR & sb.st_mode) ? 'w' : '-');
    printf("%c", (S_IXUSR & sb.st_mode) ? 'x' : '-');
    printf("%c", (S_IRGRP & sb.st_mode) ? 'r' : '-');
    printf("%c", (S_IWGRP & sb.st_mode) ? 'w' : '-');
    printf("%c", (S_IXGRP & sb.st_mode) ? 'x' : '-');
    printf("%c", (S_IROTH & sb.st_mode) ? 'r' : '-');
    printf("%c", (sb.st_mode & S_IWOTH) ? 'w' : '-');
    printf("%c  ", (S_IXOTH & sb.st_mode) ? 'x' : '-');
    printf("%d\t", sb.st_nlink);
    printf("%s\t", user_from_uid(sb.st_uid,0));
    printf("%s\t", group_from_gid(sb.st_gid,0));
    printf("%5.0lld ", sb.st_size);
    t = localtime(&sb.st_ctime);
    printf("%s ", lookup[t->tm_mon]);
    printf("%2.0d %2.0d:%2.0d ", t->tm_mday, t->tm_hour, t->tm_min);
    if(S_ISLNK(sb.st_mode)){
        printf("%s ",name );
        bytes_read = readlink(name, link_read, 254);
        link_read[bytes_read] = '\0';
        printf("-> %s\n", link_read);
    }
    else if((S_IXUSR & sb.st_mode) || (S_IXGRP & sb.st_mode) || (S_IXOTH & sb.st_mode))
        printf("%s\n", name);
    else if(S_ISFIFO(sb.st_mode))
        printf("%s\n", name);
    else
        printf("%s\n", name);
}

int _ls(const char *dir,int op_a,int op_l, int op_i) {
    //Here we will list the directory
    struct dirent *d;
    DIR *dh = opendir(dir);
    if (!dh) {
        if (errno == ENOENT) {
            perror("Directory doesn't exist");
        } else {
            perror("Unable to read directory");
        }
        return (1);
    }

    while ((d = readdir(dh)) != NULL) {
        //If hidden files are found we continue
        if (!op_a && d->d_name[0] == '.')
            continue;
        if (op_i) {
            struct stat sb;
            lstat(d->d_name, &sb);

            printf("%8.llu ", sb.st_ino);
        }

        if (op_l) {
            display_contents(d->d_name);
        } else {
            printf("%s \n", d->d_name);
        }
    }

    return 0;
}
int ls(int argc, char **argv) {
    if (argc == 0) {
        _ls(".", 0, 0, 0);
    } else if (argc == 1 && argv[0][0] == '-') {
        int op_a = 0, op_l = 0, op_i = 0;
        char *p = (char *) (argv[0] + 1);
        while (*p) {
            if (*p == 'a') {
                op_a = 1;
            } else if (*p == 'l') {
                op_l = 1;
            } else if (*p == 'i') {
                op_i = 1;
            } else {
                perror("Option not available");
                return (1);
            }
            p++;
        }
        return _ls(".", op_a, op_l, op_i);
    }
    else {
        perror("not valid options");
    }
    return 0;
}