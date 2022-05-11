#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head,*newnode,*temp;
void reverse()
{
    struct node *prev,*nextnode,*curr;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    head=prev;
    display(head);
}
void display()
{
    temp=head;
    printf("'\n");
    while(temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
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
    reverse();
}
