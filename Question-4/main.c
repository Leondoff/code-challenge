#include <stdio.h>
#include <stdlib.h>

int isCharInArray(char target, const char *charArray) {
    while (*charArray != '\0') {
        if (*charArray == target) {
            return 1; // Character found
        }
        charArray++;
    }
    return 0; // Character not found
}

int areAllCharsInArray(const char *str) {
    const char validChars [] = {'(',')','{','}','[',']','\0'};
    while (*str != '\0') {
        if (!isCharInArray(*str, validChars)) {
            return 0; // At least one character not found
        }
        str++;
    }
    return 1; // All characters found
}

int main() {
    char validChars [] = {'(',')','{','}','[',']','\0'};
    char c = '{}';


    if (areAllCharsInArray(&c)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
