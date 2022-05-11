#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*tail,*head;
struct node *newnode,*temp;
void create()
{
    head=NULL;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf(" Enter data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf(" Do you want to continue (0,1)? :");
        scanf("%d",&choice);
    }
}
void reverse()
{
    struct node *current,*nextnode,*temp;
    current=head;
    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
    }
    current=head;
    head=tail;
    tail=current;

    temp=head;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    create();
    display();
    reverse();
    // display();
}
