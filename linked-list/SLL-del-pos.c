#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void del_pos()
{
    if (head == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = head;
        int index, i = 1;
        printf("Enter the position to delete : ");
        scanf("%d", &index);
        if (index == 1)
        {
            head = temp->link;
            free(temp);
        }
        else
        {
            while (i != index)
            {
                prev = temp;
                temp = temp->link;
                i++;
            }
            prev->link = temp->link;
            free(temp);
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

    // deleing the last node
    del_pos();

    // displaying the LL
    display();
    return 0;
}