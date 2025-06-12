#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at the end of the list
void insertEnd(struct Node** head_ref, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Delete a node by position (1-based index)
void deleteAtPos(struct Node** head_ref, int pos) {
    if (*head_ref == NULL) return;

    struct Node* temp = *head_ref;
    if (pos == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    int i;
    for (i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // position out of range

    prev->next = temp->next;
    free(temp);
}

// Display all list elements
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, x, pos;

    printf("How many items to insert? ");
    scanf("%d", &n);
    printf("Enter %d numbers:\n", n);
    while (n--) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    displayList(head);

    printf("Position to delete: ");
    scanf("%d", &pos);
    deleteAtPos(&head, pos);

    displayList(head);
    return 0;
}
