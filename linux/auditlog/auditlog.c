#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define LOGFILE "audit.log"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(STDOUT_FILENO, "Usage: ./auditlog --add <message> | --view\n", 43);
        return 1;
    }

    // -------------------- ADD --------------------

    if (strcmp(argv[1], "--add") == 0)
    {
        if (argc != 3)
        {
            write(STDOUT_FILENO, "Usage: ./auditlog --add <message>\n", 34);
            return 1;
        }

        int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd < 0)
        {
            perror("open");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);

        write(STDOUT_FILENO, "Log entry added.\n", 17);
    }

    // -------------------- VIEW --------------------

    else if (strcmp(argv[1], "--view") == 0)
    {
        int fd = open(LOGFILE, O_RDONLY);

        if (fd < 0)
        {
            perror("open");
            return 1;
        }

        char buffer[BUFFER_SIZE];
        int bytesRead;
        int line = 1;

        char lineNumber[20];
        int len = sprintf(lineNumber, "%d: ", line);
        write(STDOUT_FILENO, lineNumber, len);

        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
            for (int i = 0; i < bytesRead; i++)
            {
                write(STDOUT_FILENO, &buffer[i], 1);

                if (buffer[i] == '\n')
                {
                    line++;

                    char num[20];
                    len = sprintf(num, "%d: ", line);
                    write(STDOUT_FILENO, num, len);
                }
            }
        }

        close(fd);
    }

    // -------------------- INVALID COMMAND --------------------

    else
    {
        write(STDOUT_FILENO, "Invalid command.\n", 17);
        write(STDOUT_FILENO, "Usage:\n", 7);
        write(STDOUT_FILENO, "  ./auditlog --add \"message\"\n", 29);
        write(STDOUT_FILENO, "  ./auditlog --view\n", 20);
        return 1;
    }

    return 0;
}
