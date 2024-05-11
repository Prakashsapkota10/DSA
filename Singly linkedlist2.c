//Menu driven program of Singly linked list using C

#include <stdio.h>
#include <stdlib.h>

// Declared Function Prototypes
void create(); // Create a node
void display(); // Display a node
void insert_first(); // Insert a node in the first position
void insert_last(); // Insert a node in the last position
void delete_first(); // Delete a node in the first position
void delete_last(); // Delete a node in the last position

// Declared node structure
struct node
{
    int info;
    struct node *next;
} *start = NULL;

int main()
{
    int choice;
    while (1)
    {
        printf("\n\t ******* Singly Linked List Operations *******");
        printf("\n\t 1) Create");
        printf("\n\t 2) Display");
        printf("\n\t 3) Insert_First");
        printf("\n\t 4) Insert_Last");
        printf("\n\t 5) Delete_First");
        printf("\n\t 6) Delete_Last");
        printf("\n\t 7) Exit");
        printf("\n\n");
        printf("\n\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_first();
                break;
            
            case 4:
                insert_last();
                break;
            
            case 5:
                delete_first();
                break;
            
            case 6:
                delete_last();
                break;
            case 7:
                exit(0);
            default:
                printf("\nWrong choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void create()
{
	// Implement the logic to create a new node
int data;
    printf("Enter data for the new node: ");
    scanf("%d", &data);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = data;
    newNode->next = NULL;

    if (start == NULL)
        start = newNode;
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display()
{
	// Implement the logic to display the node
if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *current = start;
    printf("List elements: ");
    while (current != NULL)
    {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");

}

void insert_first()
{
	// Implement the logic to insert a first node here
    int data;
    printf("Enter data for the new node: ");
    scanf("%d", &data);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = data;
    newNode->next = start;
    start = newNode;
}


void insert_last()
{
    // Implement the logic to insert a node at the end here
    int data;
    printf("Enter data for the new node: ");
    scanf("%d", &data);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = data;
    newNode->next = NULL;

    if (start == NULL)
        start = newNode;
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_first()
{
    // Implement the logic to delete the first node here
    if (start == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
}

void delete_last()
{
    // Implement the logic to delete the last node here
    if (start == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
    struct node *prev = NULL;
    struct node *current = start;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

