//1905622
//Nitish Kumar Sonthalia

//WAP to implement a priority queue using array
#include <stdio.h>
#include <stdlib.h>

 #define MaxRow 5
 #define MaxColumn 15

 struct MyQueue {
     int arr[MaxRow][MaxColumn];
     int front[MaxRow];
     int rear[MaxRow];
 };

 struct MyQueue makeQueue() {
     struct MyQueue retQ;
     for(int i = 0; i < MaxRow; i++) {
         for (int k = 0; k < MaxColumn; k++)
         {
             retQ.arr[i][k] = NULL;
         }
     }
     for(int i = 0; i < MaxRow; i++) {
         retQ.front[i] = -1;
         retQ.rear[i] = -1;
     }
     return retQ;
 }

 void enqueue(struct MyQueue *MQ, int data, int priority) {
     if ((MQ->front[priority] == MQ->rear[priority] + 1) || ((MQ->rear[priority] == MaxColumn - 1) && (MQ->front[priority] == 0)))
         printf("Queue Overflow \n");
     else {
         if (MQ->front[priority] == - 1) {
             MQ->front[priority] = 0;
             MQ->rear[priority] = 0;
             MQ->arr[priority][MQ->rear[priority]] = data;
         } else {
             MQ->rear[priority] += 1;
             MQ->rear[priority] = (MQ->rear[priority])%MaxColumn;
             MQ->arr[priority][MQ->rear[priority]] = data;
         }
     }
 }

 int* dequeue(struct MyQueue *MQ) {
     int pr = 0;
     while(MQ->front[pr] == -1) {
         pr++;
     }
     if(pr >= MaxRow) {
         printf("Queue Underflow \n");
         return NULL;
     } else {
         int *retVal = (int *) malloc(2 * sizeof(int));
         retVal[0] = MQ->arr[pr][MQ->front[pr]];
         retVal[1] = pr;
         if(MQ->front[pr] == MQ->rear[pr]) {
             MQ->front[pr] = -1;
             MQ->rear[pr] = -1;
         } else {
             MQ->front[pr] += 1;
             MQ->front[pr] = (MQ->front[pr])%MaxColumn;
         }
         return retVal;
     }
 }

 void display(struct MyQueue *MQ) {
     printf("\nQueue Array : \n");
     for(int i = 0; i < MaxRow; i++) {
         for (int k = 0; k < MaxColumn; k++)
         {
             printf("%d ", MQ->arr[i][k]);
         }
         printf("\n");
     }
     printf("\n");
     printf("Front Values : ");
     for(int i = 0; i < MaxRow; i++) {
         printf("%d ", MQ->front[i]);
     }
     printf("\nRear Values = ");
     for(int i = 0; i < MaxRow; i++) {
         printf("%d ", MQ->rear[i]);
     }
     printf("\n\n\n");
 }

 int main()
 {
     int choice;
     printf("1. Insert element to P.queue \n");
     printf("2. Delete element from P.queue \n");
     printf("3. Display all elements of P.queue \n");
     printf("4. Quit \n");
     struct MyQueue queue = makeQueue();
     while (1)
     {
         printf("Enter your choice : ");
         scanf("%d", &choice);
         if(choice == 1) {
             printf("Enter data : ");
             int data, priority;
             scanf("%d", &data);
             printf("Enter priority : ");
             scanf("%d", &priority);
             enqueue(&queue, data, priority);
         } else if(choice == 2) {
             int *data = dequeue(&queue);
             if(data != NULL) {
                 printf("Deleted data : %d\n", data[0]);
             }
         } else if(choice == 3) {
             display(&queue);
         } else {
             exit(0);
         }
     }
 }