#include<stdio.h>
#include<conio.h>

int count=0;
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp;
void insert_at_begin()
//if you want to insert a node before head in singly linked list use this function.
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert :");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    display(head);
}
void insert_at_end()
//if you want to insert a node at the end in singly linked list use this function.
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert :");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    display();
}
void insert_at_position()
{
    int count=10;
    newnode=(struct node*)malloc(sizeof(struct node));
    int pos,i=1;
    printf("Enter the position :");
    scanf("%d",&newnode->data);
    if(pos>count)
    {
        printf("invalid position");
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        printf("Enter data :");
        scanf("%d",newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    display();
}
void display()
{
    temp=head;
    printf("\n");
    while(temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
    printf(" %d ",count);
    printf("\n");
}
int main()
{
    head=0;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf(" Enter data :");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue (0,1) ? :");
        scanf("%d",&choice);
    }
    display(head);
    //insert_at_begin();
    //insert_at_end();
    insert_at_position();
}
