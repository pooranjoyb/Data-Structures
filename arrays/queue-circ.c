#include <stdio.h>

int front = -1;
int rear =-1;
#define size 5

int arr[size];

void enqueue(int data){
    if((front == 0 && rear == size -1) || front == rear +1){
        printf("Overflow");
        return ;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else{
        if (rear == size -1 )
        {
            rear = 0;
        }
        else rear ++;
        arr[rear] = data;   
    }
}

void dequeue(){
    if (front ==-1)
    {
        printf("Underflow");
        return ;
    }
    printf("Element deleted : %d\n", arr[front]);
    if (front == rear)
    {
        front = rear =-1;
    }
    else{
        if (front == size -1)
        {
            front = 0;
        }
        else{
            front++;
        }
    }
}

void disp(){
    int frontpos = front, rearpos = rear;
    if (front == -1)
    {
        printf("Underflow");
        return ;
    }
    printf("Queue elements : ");
    if(frontpos <= rearpos){
        while (frontpos <= rearpos)
        {
            printf("%d\t", arr[frontpos]);
            frontpos++;
        } 
    }
    else{
        while (frontpos <= size-1)
        {
            printf("%d\t", arr[frontpos]);
            frontpos++;
            
        }
        frontpos = 0;
        while (frontpos <= rear)
        {
            printf("%d\t", arr[frontpos]);
            frontpos++;
        }
    }
    printf("\n");
}

int main(){
    enqueue(11);
    enqueue(12);
    enqueue(13);
    dequeue();
    enqueue(14);
    enqueue(15);
    dequeue();
    enqueue(15);
    dequeue();
    disp();
}
