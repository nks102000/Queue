//1905622
//Nitish Kumar Sonthalia

//Double Ended Queue Check palindrome
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
int N;
char *deque;
int f=-1,r=-1;

void enqueuerear(char x)
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
        printf("%c<-->",deque[i]);
        i=(i+1)%N;
    }
    printf("%c-->",deque[r]);
}

char getfront()
{
    //printf("%d",deque[f]);
    char ch=deque[f];
    f++;
    return(ch);
}

char getrear()
{
    //printf("%d",deque[r]);
    char ch=deque[r];
    r--;
    return(ch);
}

char dequeuefront()
{
    char i=0;
    if(f==-1&&r==-1)
    {
       // printf("UNDERFLOW\n");
    }
    if(f==r)
    {
        i=deque[f];
        f=r=-1;
        //printf("%d",deque[f]);
        return(i);
    }
    else if (f==N-1)
    {
        i=deque[f];
        //printf("%d",deque[f]);
        f=0;
        return(i);
    }
    else
    {
        i=deque[f];
        //printf("%d",deque[f]);
        f++;
        return(i);

    }
}

char dequerear()
{
    char i=0;
    if(f==-1&&r==-1)
    {
        //printf("UNDERFLOW\n");
    }
    if(f==r)
    {
        i=deque[r];
        f=r=-1;
        //printf("%d",deque[r]);
        return(i);
    }
    else if(r==0)
    {
        i=deque[r];
        //printf("%d",deque[r]);
        r=N-1;
        return(i);
    }
    else
    {
        i=deque[r];
        //printf("%d",deque[r]);
        r--;
        return(i);
    }
    
}

void CheckPalindrome(){
    if(f==-1 && r==-1){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        int x=0;
        while(f!=r){
            if(dequeuefront()!=dequerear()){
                x=1;
                break;
            }
        }
        if(x==0){
            printf("The Statenemt is palindrome\n");
        }
        else{
            printf("The Statenemt is not palindrome\n");
        }
    }
}

int main(){

    char str[20];
    printf("\nEnter the statement:");
    gets(str);
    N=strlen(str);
    deque=(char*)malloc(N*sizeof(char));
    for(int i=0;i<N;i++){
        enqueuerear(str[i]);
    }
    CheckPalindrome();
    return 0;
}