#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void del_end()
{
    if (head == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            temp = temp->link;
            free(head);
            head = temp;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}

int main(void)
{
    struct node *temp = NULL, *temp1 = NULL, *trav = NULL;
    head = malloc(sizeof(struct node));
    temp = malloc(sizeof(struct node));
    temp1 = malloc(sizeof(struct node));

    // first node with its link
    head->data = 10;
    head->link = temp;

    // second node with its link
    temp->data = 20;
    temp->link = temp1;

    // third node with its link
    temp1->data = 30;
    temp1->link = NULL;

    // deleing entire LL
    del_end();

    // displaying the LL
    display();
    return 0;
}