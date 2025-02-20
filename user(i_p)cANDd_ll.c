#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
 
int main(){
    struct node *head,*temp,*newnode;
    head=0;
   int choice;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data in node: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            temp=temp->next;
        }
        printf("enter the choice(0,1): ");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp->next>=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}