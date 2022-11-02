#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void create_node(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    head = temp;
}
void create_List(int n)
{
    int data;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter elem %d : ", i);
        scanf("%d", &data);
        insert_end(data);
    }   
}

void insert_end(int data)
{
    struct node *temp = head, *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display()
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

int main()
{
    int n, head;
    printf("Enter the number of nodes you need : ");
    scanf("%d", &n);
    printf("Enter elem 1 : ");
    scanf("%d", &head);
    create_node(head);
    if (n != 1)
        create_List(n);
    display();
    return 0;
}