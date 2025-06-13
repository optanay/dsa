#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

bool isEmpty() {
    return front == rear;  
}

bool isFull() {
    return rear == MAX; 
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue overflow ✅\n");
        return;
    }
    queue[rear++] = x;
    printf("Enqueued %d\n", x);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow — no items to dequeue\n");
        return -1;
    }
    return queue[front++];
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Peeking: %d\n", peek());
    
    printf("Dequeued: %d\n", dequeue());
    display();

    return 0;
}
