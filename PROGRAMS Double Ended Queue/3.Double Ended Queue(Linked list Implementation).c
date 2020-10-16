#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct MyQueue{
    struct node *front;
    struct node *rear;
};

struct MyQueue makeQueue(){
    struct MyQueue retQ;
    retQ.front = NULL;
    retQ.rear = NULL;
    return retQ;
}

void enqueuefront(struct MyQueue *MQ, int data){
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(newNode == NULL) {
        printf("Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if((MQ)->front==NULL && (MQ)->rear==NULL){
        (MQ)->front = newNode;
        (MQ)->rear = newNode;
    }
    else{
        newNode->next=(MQ)->front;
        (MQ)->front = newNode;
    }
}

void enqueuerear(struct MyQueue *MQ, int data){
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(newNode == NULL) {
        printf("Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if((MQ)->front==NULL && (MQ)->rear==NULL){
        (MQ)->front = newNode;
        (MQ)->rear = newNode;
    }
    else{
        (MQ)->rear->next = newNode;
        (MQ)->rear = newNode;
    }
}

int dequeuefront(struct MyQueue *MQ){
    if((MQ)->front==NULL){
        printf("UNDERFLOW\n");
        return NULL;
    }
    else{
        int d=(MQ)->front->data;
        struct MyQueue *temp=(MQ)->front;
        (MQ)->front=(MQ)->front->next;
        free(temp);
        return d;
    }
}

int dequeuerear(struct MyQueue *MQ){
    if((MQ)->rear==NULL){
        printf("UNDERFLOW\n");
        return NULL;
    }
    else{
        int d=(MQ)->rear->data;
        struct node *temp=(MQ)->rear;
        struct node *current=MQ->front;
        if(current==temp){
            MQ->front=NULL;
            MQ->rear=NULL;
        }
        else{
            while(current->next!=MQ->rear){
                current=current->next;
            }
            MQ->rear=current;
            current->next=NULL;
        }
        free(temp);
        return d;
    }
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
void display(struct MyQueue*MQ) {
    int i;
    printf("Elements in the Queue : ");
    if ((MQ)->front == NULL)
        printf("None");
    else {
        struct MyQueue temp = makeQueue();
        while ((MQ)->front != NULL) {
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

int main()
{
    int choice;
    printf("1. Insert element to queue from front \n");
    printf("2. Insert element to queue from rear \n");
    printf("3. Delete element from queue front\n");
    printf("4. Delete element from queue rear\n");
    printf("5. Display all elements of queue \n");
    printf("6. Quit \n");
    struct MyQueue queue = makeQueue();
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            enqueuefront(&queue, data);
        } else if(choice == 2) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            enqueuerear(&queue, data);
        } else if(choice == 3) {
            int data = dequeuefront(&queue);
            if(data != NULL) {
                printf("Deleted data : %d\n", data);
            }
        } else if (choice == 4) {
            int data = dequeuerear((&queue));
            if(data != NULL) {
                printf("Deleted data : %d\n", data);
            }
        } else if (choice == 5) {
            display(&queue);
        } else {
            exit(0);
        }
    }
}
