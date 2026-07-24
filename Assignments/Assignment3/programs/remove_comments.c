#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int c, next;

    while ((c = fgetc(fp)) != EOF) {

        // String literal
        if (c == '"') {
            putchar(c);

            while ((c = fgetc(fp)) != EOF) {
                putchar(c);

                if (c == '\\') {
                    c = fgetc(fp);
                    if (c != EOF)
                        putchar(c);
                } else if (c == '"') {
                    break;
                }
            }
        }

        // Character literal
        else if (c == '\'') {
            putchar(c);

            while ((c = fgetc(fp)) != EOF) {
                putchar(c);

                if (c == '\\') {
                    c = fgetc(fp);
                    if (c != EOF)
                        putchar(c);
                } else if (c == '\'') {
                    break;
                }
            }
        }

        // Possible comment
        else if (c == '/') {

            next = fgetc(fp);

            // Single-line comment
            if (next == '/') {
                while ((c = fgetc(fp)) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            }

            // Multi-line comment
            else if (next == '*') {
                int prev = 0;

                while ((c = fgetc(fp)) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }

            // Not a comment
            else {
                putchar(c);

                if (next != EOF)
                    ungetc(next, fp);
            }
        }

        else {
            putchar(c);
        }
    }

    fclose(fp);
    return 0;
}
