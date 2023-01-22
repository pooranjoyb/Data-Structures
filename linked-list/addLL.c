#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    struct node *res = NULL; // head of the result linked list
    struct node *temp, *prev = NULL;
    int carry = 0, sum;
    
    while (l1 != NULL || l2 != NULL) {
        sum = carry + (l1? l1->val : 0) + (l2? l2->val : 0);
        
        carry = (sum >= 10)? 1 : 0;

        sum = sum % 10;

        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = sum;
        temp->next = NULL;

        if(res == NULL) res = temp;
        else prev->next = temp;
        
        prev  = temp;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    if (carry > 0) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = carry;
        temp->next = NULL;
        prev->next = temp;
    }
    
    return res;
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct node *node)
{
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}
int main()
{
    struct node* l1 = NULL;
    struct node* l2 = NULL;
    struct node* res = NULL;

    push(&l1, 1);
    push(&l1, 2);
    push(&l1, 3);
    printf("First number is:  ");
    printList(l1);

    push(&l2, 4);
    push(&l2, 5);
    push(&l2, 6);
    printf("Second number is: ");
    printList(l2);

    res = addTwoNumbers(l1, l2);
    printf("Result is: ");
    printList(res);

    return 0;
}

