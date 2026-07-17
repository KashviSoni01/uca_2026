#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }

    return length;
}

void reverse_string(char *str) {
    int start = 0;
    int end = my_strlen(str) - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    reverse_string(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
