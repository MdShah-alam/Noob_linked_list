#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head,*newnode,*temp;
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
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
    getch();
}

