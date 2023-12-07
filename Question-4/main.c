#include <stdio.h>
#include <regex.h>

int isValidString(const char *input) {
    regex_t regex;
    const char *pattern = "^[A-Z]*$|\\[.*\\]|\\{.*\\}|\\(.*\\)$";

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Error compiling regex pattern\n");
        return 0; // Error
    }

    int match = regexec(&regex, input, 0, NULL, 0);

    regfree(&regex);

    return match == 0;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character at the end (if present)
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    if (isValidString(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}
