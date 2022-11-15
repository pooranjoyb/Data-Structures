#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

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

void palindrome()
{
    int n = 0;
    struct node *right = head;
    struct node *left = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left != right)
    {
        if (left->data == right->data)
        {
            left = left->next;
            right = right->prev;
        }
        else {n = -1; break;}
    }

    if (n == 0)
    {
        printf("palindrome");
    }
    else
        printf("not palindrome");
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
void create_node(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    head = temp;
}

int main()
{
    create_node(10);
    insert_end(12);
    insert_end(9);
    insert_end(3);
    insert_end(12);
    insert_end(10);
    // insert_end(15);
    display();
    palindrome();
    return 0;
}