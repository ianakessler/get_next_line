#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linha: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}
