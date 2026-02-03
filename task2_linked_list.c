#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* deleteValue(struct Node *head, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("✅ Deleted %d from the list.\n", value);
        return head;
    }

    struct Node *prev = head;
    struct Node *curr = head->next;

    while (curr != NULL) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            printf("✅ Deleted %d from the list.\n", value);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("❌ Value %d not found in the list.\n", value);
    return head;
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("📌 Linked List: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value;

    printf("===== CODTECH TASK 2: LINKED LIST =====\n");

    while (1) {
        printf("\n1. Insert (End)\n2. Delete (Value)\n3. Traverse\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                printf("✅ Inserted %d\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteValue(head, value);
                break;

            case 3:
                traverse(head);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
