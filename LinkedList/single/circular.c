#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node *createNode(int x)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int x)
{
    node *newNode = createNode(x);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtBeg(int x)
{
    node *newNode = createNode(x);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insert(int x, int idx)
{
    node *newNode = createNode(x);
    if (idx == 0)
    {
        insertAtBeg(x);
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeg()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
    }
}

void delete(int idx)
{
    if (idx == 0)
    {
        deleteAtBeg();
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void display()
{
    node *temp = head;

    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> ", temp->data);
}

int main()
{
    int choice, data, idx;

    while (choice != 8)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at index\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeg(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter index: ");
            scanf("%d", &idx);
            insert(data, idx);
            break;
        case 4:
            deleteAtBeg();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter index: ");
            scanf("%d", &idx);
            delete(idx);
            break;
        case 7:
            display();
            break;
        case 8:
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}