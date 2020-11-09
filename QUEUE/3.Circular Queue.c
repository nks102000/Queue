//1905622
//Nitish Kumar Sonthalia
/*WAP to give menu to implement a circulatr queue:
    insert
    deleteion
    display(using array)*/
//Circular queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct MyQueue {
    int arr[MAX];
    int front;
    int rear;
};

struct MyQueue makeQueue() {
    struct MyQueue retQ;
    retQ.front = -1;
    retQ.rear = -1;
    return retQ;
}
 
void enqueue(struct MyQueue *MQ, int data) {
    if ((MQ->front == MQ->rear + 1) || ((MQ->rear == MAX - 1) && (MQ->front == 0)))
        printf("Queue Overflow \n");
    else {
        if (MQ->front == - 1) {
            MQ->front = 0;
            MQ->rear = 0;
            MQ->arr[MQ->rear] = data;
        } else {
            MQ->rear += 1;
            MQ->rear = (MQ->rear)%MAX;
            MQ->arr[MQ->rear] = data;
        }
    }
}

int dequeue(struct MyQueue *MQ) {
    if (MQ->front == -1) {
        printf("Queue Underflow \n");
        return NULL;
    } else {
        int retVal = MQ->arr[MQ->front];
        if(MQ->front == MQ->rear) {
            MQ->front = -1;
            MQ->rear = -1;
        } else {
            MQ->front += 1;
            MQ->front = (MQ->front)%MAX;
        }
        return retVal;
    }
}

void display(struct MyQueue MQ) {
    int i;
    printf("Elements in the Queue : ");
    if (MQ.front == -1)
        printf("None");
    else {
        int len;
        if(MQ.front > MQ.rear) {
            len = MAX - MQ.rear + MQ.front + 1;
        } else {
            len = MQ.rear - MQ.front + 1;
        }
        for(int i = 0; i < len; i++) {
            int data = dequeue(&MQ);
            printf("%d ", data);
            enqueue(&MQ, data);
        }
    }
    printf("\n");
}

void revQueue(struct MyQueue *MQ) {
    if(MQ->front == -1) {
        return;
    }
    int data = dequeue(MQ);
    revQueue(MQ);
    enqueue(MQ, data);
}

int main()
{
    int choice;
    printf("1. Insert element to queue \n");
    printf("2. Delete element from queue \n");
    printf("3. Display all elements of queue \n");
    printf("4. Reverse the Queue \n");
    printf("5. Quit \n");
    struct MyQueue queue = makeQueue();
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            enqueue(&queue, data);
        } else if(choice == 2) {
            int data = dequeue(&queue);
            printf("Deleted data : %d\n", data);
        } else if(choice == 3) {
            display(queue);
        } else if (choice == 4) {
            revQueue(&queue);
        } else {
            exit(0);
        }
    }
}