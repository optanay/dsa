#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack overflow—cannot push %d\n", x);
        return;
    }
    stack[++top] = x;
    printf("Pushed %d\n", x);
}


int pop() {
    if (isEmpty()) {
        printf("Stack underflow—cannot pop\n");
        return -1;  
    }
    int val = stack[top--];
    printf("Popped %d\n", val);
    return val;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty—no top element\n");
        return -1;
    }
    printf("Top is %d\n", stack[top]);
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents (top → bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1: Push  2: Pop  3: Peek  4: Display  5: Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
