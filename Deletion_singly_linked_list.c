#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head,*temp,*newnode;
void deletion_head()
//if somebody wants to delete head node in singly linked list.
{
    temp=head;
    head=head->next;
    free(temp);//to  clear memory
    display(head);
}
void deletion_end_node()
//if somebody wants to delete last node in singly linked list.
{
    struct node *prevnode;
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
    }
    else
    {
        prevnode->next=NULL;
        free(temp);
    }
    display(head);
}
void deletion_from_position()
//if somebody wants to delete node at any position in singly linked list.
{
    struct node *nextnode;
    int pos,i=1;
    temp=head;
    printf("Enter position which node will be deleted :");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;//The node which you want to delete.
    temp->next=nextnode->next;
    free(nextnode);
    display(head);
}
void display()
{
    temp=head;
    printf("\n");
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
    //deletion_head();
    //deletion_end_node();
    deletion_from_position();
    getch();
}
