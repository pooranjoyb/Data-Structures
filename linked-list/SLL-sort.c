#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail = NULL;
void addNode(int data)
{

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {

        head = newNode;
        tail = newNode;
    }
    else
    {

        tail->next = newNode;
        tail = newNode;
    }
}

void sortList()
{

    struct node *temp = head, *p ;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            p = temp;
            while (p->next != NULL)
            {
                if (p->data > (p->next)->data)
                {
                    int var = (p->next)->data;
                    (p->next)->data = p->data;
                    p->data = var;
                }
                p = p->next;
            }
            temp = temp->next;
        }
    }
}


void display()
{

    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    while (current != NULL)
    {

        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    addNode(-2);
    addNode(5);
    addNode(-9);
    addNode(-6);
    addNode(-3);
    addNode(-1);
    addNode(1);
    addNode(6);
    printf("Original list: \n");
    display();
    sortList();
    printf("Sorted list: \n");
    display();

    return 0;
}