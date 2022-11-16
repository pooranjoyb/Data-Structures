#include <stdio.h>
int front = -1, rear = -1;
#define size 5
int arr[size];

void enqueue(int data)
{
    if (rear == size -1)
        printf("Overflow");

    else
    {   if (front == -1)
    {
        front = 0;
    }
    
        rear++;
        arr[rear] = data;
    }
}

void dequeue()
{
    if (rear == -1 || front > rear)
        printf("Underflow");
    else{
        printf("Element deleted : %d\n", arr[front]);
        front++;
    }
}

void disp(){
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", arr[i]);
    }
    
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(15);
    dequeue();
    disp();
}