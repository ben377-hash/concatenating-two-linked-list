// concatenating two linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Node;

void create(Node **ref,int val){
    Node *temp,*new;
    while(val--){
        new = malloc(sizeof(Node));
        printf("Enter the data --> ");
        scanf("%d",&new->data);
        new->link=NULL;
        if(*ref==NULL){
            *ref=temp=new;
        }
        else{
            temp->link=new;
            temp=new;
        }
    }
}
void catenate(Node **first,Node **second){
    Node *temp=*first;
    while(temp->link!=NULL){
        temp=temp->link;
    } 
    temp->link=(*second);
    *second=NULL;
}
void display(Node *block){
    Node *temp=block;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
int main(){
   // int val;
    Node *first=NULL,*second=NULL;
    printf("How many first elements ? \n");
    int x;
    scanf("%d",&x);
    create(&first,x);
    printf("How many second elements ? \n");
    int y;
    scanf("%d",&y);
    create(&second,y);
     
    printf("Entered first elements are: \n");
    display(first);
    printf("Entered second elements are: \n");
    display(second);

    catenate(&first,&second);
    printf("\n After catenation \n");
    display(first);
    return 0;
}

