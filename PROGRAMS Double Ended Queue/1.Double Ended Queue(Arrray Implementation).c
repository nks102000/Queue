//1905622
//Nitish Kumar Sonthalia

//Double Ended Queue(Arrray Implementation)
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define N 5
int deque[N];
int f=-1,r=-1;

void enqueuefront(int x)
{
    if((f==0 && r==N-1)||(f==r+1))
    {
        printf("Queue is full\n");
    }
    else if(f==-1 && r==-1)
    {
        f=r=0;
        deque[f]=x;
    }
    else if(f==0 )
    {
        f=N-1;
        deque[f]=x;
    }
    else
    {
        f--;
        deque[f]=x;
    }
    
}
void enqueuerear(int x)
{
    if((f==0 && r==N-1)||(f==r+1))
    {
        printf("Queue is full\n");
    }
    else if(f==-1 && r==-1)
    {
        f=r=0;
        deque[r]=x;
    }
    else if (r==N-1)
    {
        r=0;
        deque[r]=x;
    }
    else
    {
        r++;
        deque[r]=x;
    }
}

void display()
{
    int i=f;
    while(i!=r)
    {
        printf("%d<-->",deque[i]);
        i=(i+1)%N;
    }
    printf("%d-->",deque[r]);
}

void getfront()
{
    printf("%d",deque[f]);
}

void getrear()
{
    printf("%d",deque[r]);
}

void dequeuefront()
{
    if(f==-1&&r==-1)
    {
        printf("UNDERFLOW\n");
    }
    else if(f==r)
    {
        f=r=-1;
        printf("%d",deque[f]);
    }
    else if (f==N-1)
    {
        printf("%d",deque[f]);
        f=0;
    }
    else
    {
        printf("%d",deque[f]);
        f++;

    }
}

void dequerear()
{
    if(f==-1&&r==-1)
    {
        printf("UNDERFLOW\n");
    }
    else if(f==r)
    {
        f=r=-1;
        printf("%d",deque[r]);
    }
    else if(r==0)
    {
        printf("%d",deque[r]);
        r=N-1;
    }
    else
    {
        printf("%d",deque[r]);
        r--;
    }
    
}

int main(){
    printf("\nMenu");
    printf("\n1.Implement input restricted queue.");
    printf("\n2.Implement output restricted queue.");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
        printf("\n1.Insert element");
        printf("\n2.Delete from start");
        printf("\n3.EDelete From End");
        printf("\n4.Display");
        printf("\n5.Exit");
        int c,e;
        while(1){
            printf("\nEnter your choice:");
            scanf("%d",&c);
            switch(c){
                case 1:
                    printf("\nEnter the data");
                    scanf("%d",&e);
                    enqueuerear(e);
                    break;
                case 2:
                    printf("\nElement removed:");
                    dequeuefront();
                    break;
                case 3:
                    printf("\nElement removed:");
                    dequerear();
                    break;
                case 4:
                    printf("\nElement are:");
                    display();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    exit(0);
                    break; 
            }   
        }
    }
    else if(ch==2){
        printf("\n1.Insert at start");
        printf("\n2.Insert at Last");
        printf("\n3.Delete from start");
        printf("\n4.Display");
        printf("\n5.Exit");
        int c,e;
        while(1){
            printf("\nEnter your choice:");
            scanf("%d",&c);
            switch(c){
                case 1:
                    printf("\nEnter the data");
                    scanf("%d",&e);
                    enqueuefront(e);
                    break;
                case 2:
                    printf("\nEnter the data");
                    scanf("%d",&e);
                    enqueuerear(e);
                    break;
                case 3:
                    printf("\nElement removed:");
                    dequeuefront();
                    break;
                case 4:
                    printf("\nElement are:");
                    display();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    exit(0);
                    break; 
            }
        }
    }
    return 0;
}