#include <stdio.h>


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int array[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack))
        return;

    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        exit(1);

    return stack->array[stack->top--];
}

int isCharInArray(char target, const char *charArray) {
    while (*charArray != '\0') {
        if (*charArray == target) {
            return 1; // Character found
        }
        charArray++;
    }
    return 0;
}

int areAllCharsInArray(const char *str, const char *charArray) {
    while (*str != '\0') {
        if (!isCharInArray(*str, charArray)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void pushAll(struct Stack* stack, const char* str) {
    while (*str != '\0') {
        push(stack, *str);
        str++;
    }
}

int areCharsInAscendingOrderInStack(struct Stack* stack) {
    while (stack->top > 0) {
        char current = pop(stack);
        char next = pop(stack);

        if (current > next) {
            return 0; // Characters are not in ascending order
        }
    }
    return 1; // Characters are in ascending order
}

int main() {
    char validChars[] = {'(', ')', '{', '}', '[', ']', '\0'};
    char input;

    printf("Enter a string: ");
    scanf("%c", &input);

    struct Stack myStack;
    pushAll(&myStack, &input);

    int r = areCharsInAscendingOrderInStack(&myStack);

    printf(">>>>>>>>>>>>>>>>>> %d",r);

    if (areAllCharsInArray(&input, validChars)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
