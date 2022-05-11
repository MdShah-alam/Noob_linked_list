#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*tail;
struct node *head,*newnode,*temp;
void create()
{
    head=NULL;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf(" Enter data :");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
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
void insert_at_head()
{
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf(" Enter data :");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        printf(" Do you want to continue (0,1)? :");
        scanf("%d",&choice);
    }
}
void insert_at_end()
{
    struct node* tail;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf(" Enter data :");
    scanf("%d",newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    temp=tail;
}
void insert_at_position()
{
    int count=10;
    int pos,i=1;
    int choice=1;
    printf(" Enter your position :");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("invalid positon");
    }
    else if(pos==1)
    {
        insert_at_head();
    }
    else
    {
        temp=head;
        while(choice)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf(" Enter data :");
            scanf("%d",&newnode->data);
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
            printf(" Do you want to continue (0,1) ? :");
            scanf("%d",&choice);
        }
    }
}
void display()
{
    struct node *temp;
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
    //insert_at_head();
    //insert_at_end();
    insert_at_position();
    display();
    //display();
    getch();
}
