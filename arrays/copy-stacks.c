//copying even elements of stack in another stack

#include <stdio.h>
int size = 5;
int  stack[5];
int top = -1;

void push(int elem)
{
    if (top == size)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = elem;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    
    printf("Element %d popped out", stack[top]);
    top--;
}

void disp()
{
    for (int i = 0; i < top + 1; i++)
    {
        printf("%d\t", stack[i]);
    }
}

int main()
{
    push(10);
    push(20);
    push(21);
    push(230);
    push(25);
    printf("\n");
    disp();
    printf("\n");
    int arr[3];
    int j = 0;
    for (int i = 0; i < top+1; i++)
    {
        if (i % 2 == 0)
        {

           arr[j] = stack[i];
           j++;
        }
        
    }
    for (int i = 0; i < j; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    
}
