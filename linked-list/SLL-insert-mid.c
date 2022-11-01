#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void insert_mid()
{
    struct node *new;
    new = malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = new;
        printf("LL is empty");
    }
    else
    {
        int i = 1, pos, value;
        printf("Enter data to insert : ");
        scanf("%d", &value);
        printf("Enter the position to insert : ");
        scanf("%d", &pos);
        struct node *temp = head;
        new->data = value;
        while (i != pos)
        {
            i++;
            temp = temp->link;
        }
        //linking should be done first otherwise there is no chance we get the node after the inserted node
        new->link = temp->link;
        temp->link = new;
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

    // inserting at middle
    insert_mid();

    // displaying the LL
    display();
    return 0;
}