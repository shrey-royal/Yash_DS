#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

//Function Declarations
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void searchByValue(struct Node** head, int data);
void lengthOfList(struct Node** head);
void reverseList(struct Node** head);
void deleteAtBeginning(struct Node** head);
void deleteAtEnd(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void displayForward(struct Node** head);
void displayReverse(struct Node** head);

void main() {
    int n, choice, data, position, key;
    struct Node* head = NULL;

    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. SearchByValue");
        printf("\n5. Length of list");
        printf("\n6. Reverse the list");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete at end");
        printf("\n9. Delete at position");
        printf("\n10. Display in forward direction");
        printf("\n11. Display in reverse direction");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");  //clrscr();
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                system("cls");  //clrscr();
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            
            default:
                break;
        }
    }
    
}

void insertAtBeginning(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}