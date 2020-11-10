//1905622
//Nitish Kumar Sonthalia
 
//WAP to implement a stack adt using a queue adt


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct MyQueue {
    struct node *front;
    struct node *rear;
};

struct MyQueue makeQueue() {
    struct MyQueue retQ;
    retQ.front = NULL;
    retQ.rear = NULL;
    return retQ;
}
void enqueue(struct MyQueue *MQ, int data) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(newNode == NULL) {
        printf("Overflow\n");
        return;
    }
    newNode->next = NULL;
    newNode->data = data;
    if(MQ->front == NULL) {
        MQ->front = newNode;
    } else {
        MQ->rear->next = newNode;
    }
    MQ->rear = newNode;
}
int dequeue(struct MyQueue *MQ) {
    if (MQ->front == NULL) {
        printf("Queue Underflow \n");
        return NULL;
    } else {
        struct node *temp = MQ->front;
        if(temp->next == NULL) {
            MQ->front = NULL;
            MQ->rear = NULL;
        } else {
            MQ->front = MQ->front->next;
        }
        int data = temp->data;
        free(temp);
        return data;
    }
}
void display(struct MyQueue *MQ) {
    int i;
    printf("Elements in the Queue : ");
    if (MQ->front == NULL)
        printf("None");
    else {
        struct MyQueue temp = makeQueue();
        while (MQ->front != NULL) {
            int data = dequeue(MQ);
            printf("%d ", data);
            enqueue(&temp, data);
        }
        while (temp.front != NULL)
        {
            enqueue(MQ, dequeue(&temp));
        }
        
    }
    printf("\n");
}
void push(struct MyQueue *MQ, int data){
    struct MyQueue queue = makeQueue();
    enqueue(&queue,data);
    while(MQ->front!=NULL){
        int t= dequeue(MQ);
        enqueue(&queue,t);
    }
    *MQ=queue;
}
int pop(struct MyQueue *MQ){
    int t=dequeue(MQ);
    return t;
}

int main(){
    int choice;
    printf("1. Insert element to Stack \n");
    printf("2. Delete element from Stack \n");
    printf("3. Display all elements of Stack \n");
    printf("4. Quit \n");
    struct MyQueue queue = makeQueue();
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            push(&queue, data);
        } else if(choice == 2) {
            int data = pop(&queue);
            if(data != NULL) {
                printf("Deleted data : %d\n", data);
            }
        } else if(choice == 3) {
            display(&queue);
        } else {
            exit(0);
        }
    }
}
