#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef struct {
    // You can modify this struct based on your picture representation
    // For simplicity, let's assume each picture is represented by an integer
    int data;
} Picture;

typedef struct {
    Picture items[MAX_STACK_SIZE];
    int top;
} PictureStack;

// Function prototypes
void initializeStack(PictureStack *stack);
int isStackEmpty(const PictureStack *stack);
int isStackFull(const PictureStack *stack);
void push(PictureStack *stack, Picture picture);
Picture pop(PictureStack *stack);
void displayStack(const PictureStack *stack);

int main() {
    PictureStack stack;
    initializeStack(&stack);

    int choice;
    Picture picture;

    do {
        printf("\n1. Push Picture\n");
        printf("2. Pop Picture\n");
        printf("3. Display Pictures\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isStackFull(&stack)) {
                    printf("Enter picture data: ");
                    scanf("%d", &picture.data);
                    push(&stack, picture);
                    printf("Picture pushed onto the stack.\n");
                } else {
                    printf("Stack is full. Cannot push more pictures.\n");
                }
                break;
            case 2:
                if (!isStackEmpty(&stack)) {
                    picture = pop(&stack);
                    printf("Popped picture with data: %d\n", picture.data);
                } else {
                    printf("Stack is empty. Cannot pop a picture.\n");
                }
                break;
            case 3:
                if (!isStackEmpty(&stack)) {
                    printf("Pictures in the stack:\n");
                    displayStack(&stack);
                } else {
                    printf("Stack is empty. No pictures to display.\n");
                }
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

void initializeStack(PictureStack *stack) {
    stack->top = -1;
}

int isStackEmpty(const PictureStack *stack) {
    return stack->top == -1;
}

int isStackFull(const PictureStack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(PictureStack *stack, Picture picture) {
    if (!isStackFull(stack)) {
        stack->items[++stack->top] = picture;
    }
}

Picture pop(PictureStack *stack) {
    Picture picture;
    if (!isStackEmpty(stack)) {
        picture = stack->items[stack->top--];
        return picture;
    }
    // Return a dummy picture if the stack is empty
    picture.data = -1;
    return picture;
}

void displayStack(const PictureStack *stack) {
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->items[i].data);
    }
    printf("\n");
}