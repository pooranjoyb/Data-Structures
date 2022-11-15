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

void palindrome()
{
    int n = 0;
    struct node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *prev = NULL, *next = NULL;
    while (slow != NULL)
    {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    slow = prev;

    struct node *temp = head;
    while(slow != NULL){
        if(temp -> data == slow ->data)
        {
            temp = temp->next;
            slow = slow->next;
        }
        else {
            n = -1;
        break;}
    }
    if (n==0)
    {
        printf("Palindrome");
    }
    else{
        
        printf("Not Palindrome");
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
    addNode(1);
    addNode(2);
    addNode(8);
    addNode(8);
    addNode(2);
    addNode(1);
    display();
    palindrome();

    return 0;
}