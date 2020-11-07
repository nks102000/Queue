//1905622
//Nitish Kumar Sonthalia

/*WAP to implement linear queue adt:
    insert
    deleteion
    display
    reverse(using array)*/
//Queue ADT

#include<stdio.h>
#include<stdlib.h>
#define max 20

struct queue
{
    int qu[max];
    int f;
    int r;
};

struct queue makeQueue() {
    struct queue retQ;
    retQ.f = -1;
    retQ.r = -1;
    return retQ;
}

void insert(struct queue *q,int data){
    if((q)->r==max-1){
        printf("\n Overflow");
        return;
    }
    if((q)->f==-1 && (q)->r==-1){
        (q)->f=0;
        (q)->r=0;
        (q)->qu[(q)->r]=data;
    }
    else{
        ((q)->r)++;
        (q)->qu[(q)->r]=data;
    }
}

int delete_e(struct queue *q){
    if((q)->f==-1 && (q)->r==-1){
        printf("\n Underflow");
        return NULL;
    }
    else if((q)->f==(q)->r){
        int t=(q)->qu[(q)->f];
        (q)->f=-1;
        (q)->r=-1;
        return t;
    }
    else{
    int t=(q)->qu[(q)->f];
    ((q)->f)++;
    return t;
    }   
}

void display(struct queue q){
    struct queue q1=makeQueue();
    int len;
    len = q.r - q.f + 1;

    for (int i = 0; i < len; i++)
    {
        int t=delete_e(&q);
        printf("%d ",t);
        insert(&q1,t);
    }

    for (int i = 0; i < len; i++)
    {
        int t=delete_e(&q1);
        insert(&q,t);
    }

}

void rev_queue(struct queue *q){
    if((q)->f==-1 && (q)->r==-1){
        return NULL;
    }
    int t=delete_e(q);
    rev_queue(q);
    insert(q,t);
}

int main(){
    struct queue q=makeQueue();
    while(1){
        printf("\nMenu:");
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Display");
        printf("\n4.Reverse");
        printf("\n5.Exit");
        printf("\nEnter Choice:");
        int n,p;
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("\nEnter Element:");
                scanf("%d",&p);
                insert(&q,p);
                break;
            case 2:
               p=delete_e(&q);
               printf("\nElement %d deleted",p);
               break;
            case 3:
               printf("\nElement are:");
               display(q);
               break;
            case 4:
                rev_queue(&q);
                break;
            case 5:
                exit(1);
                break;
            default:
                break;
        }
    }
    return 0;
}