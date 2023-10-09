#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

//Function to create a new Node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);    //abnormal termination
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
}

//Function to isnert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

//Function to insert a node at a given position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if(position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if(position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    for(int i=1; i<position-1; i++) {
        if(current == NULL) {
            printf("Position exceeds the length of the list!\n");
            return;
        }
        current = current->next;
    }
    if(current == NULL) {
        printf("Position exceeds the length of the list!\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

//Function to print the list in forward direction
void printList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//Function to print the list in reverse direction
void printListReverse(struct Node* head) {
    if(head == NULL) {
        return;
    }
    printListReverse(head->next);
    printf("%d -> ", head->data);
}

void main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while(1) {
        system("pause");
        system("cls");
        printf("\n1. Insertion at the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion at a given position\n");
        printf("4. Search by Value\n");
        printf("5. Length of the list\n");
        printf("6. Reverse the list\n");
        printf("7. Delete at the beginning\n");
        printf("8. Delete at the end\n");
        printf("9. Delete at a given position\n");
        printf("88. Print list in forward Direction\n");
        printf("99. Print list in reverse Direction\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {    
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 88:
                printf("List in forward direction:\n");
                printList(head);
                break;

            case 99:
                printf("List in reverse direction:\n");
                printListReverse(head);
                printf("NULL\n");
                break;
        
            case 0:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }


}