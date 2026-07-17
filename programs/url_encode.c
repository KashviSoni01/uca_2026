#include <stdio.h>

void url_encode(char *str, int true_length) {
    int spaces = 0;

    // Count spaces
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ')
            spaces++;
    }

    int new_length = true_length + spaces * 2;

    // Null terminate the new string
    str[new_length] = '\0';

    // Work backwards
    for (int i = true_length - 1, j = new_length - 1; i >= 0; i--) {

        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {

    char str[100];
    int true_length;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter true length: ");
    scanf("%d", &true_length);

    // Remove newline if present
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    url_encode(str, true_length);

    printf("URL Encoded String: %s\n", str);

    return 0;
}
