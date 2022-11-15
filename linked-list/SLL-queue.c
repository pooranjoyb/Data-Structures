#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void enqueue(int data)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = NULL;
    }
}

void dequeue()
{
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
}

void disp()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
}

int main()
{
    int ch;
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nEnter the operation : ");
    scanf("%d", &ch);
    while (1)
    {
        switch (ch)
        {
        case 1:
            int n;
            printf("\nEnter data to be inserted : ");
            scanf("%d", &n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            disp();
            break;
        }
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nEnter the operation : ");
        scanf("%d", &ch);
    }
}
