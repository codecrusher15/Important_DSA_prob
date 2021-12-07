#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void insert_ll(int pos,int data,struct node **head);
void del_ll(int pos,struct node** head);
void update_ll(int pos,int data,struct node* head);
int max_ll(struct node* head);
int main()
{
    struct node * head = NULL;
    int q,t,k,v;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d",&t);
        switch (t)
        {
        case 1: //insert
            scanf("%d %d",&k,&v);
            insert_ll(k,v,&head); 
            break;
        case 2: //del
            scanf("%d",&k);
            del_ll(k,&head);
            break;
        case 3: //update
            scanf("%d %d",&k,&v);
            update_ll(k,v,head);
            break;
        case 4: //printf max value
            printf("%d\n",max_ll(head));
            break;
        default:
            printf("Invalid query");
            break;
        }
    }
}
void insert_ll(int pos,int data,struct node **head) //Insert function
{
    struct node* temp = *head;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    struct node* temp1 = (struct node*)(malloc(sizeof(struct node)));
    temp1->data = data;
    if(pos != 0)    //inserting at pos
    {
        temp1->next = temp->next;
        temp->next = temp1;
    }
    else        //inserting at beginning i.e pos 0
    {
        temp1->next = *head;
        *head = temp1;
    };
}
void del_ll(int pos,struct node** head) //function to delete node
{
    struct node* temp = *head;
    if(pos == 0)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    struct node* temp1;
    temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
}
void update_ll(int pos,int data,struct node* head)  //function to update data
{
    for (int  i = 0; i < pos; i++)
    {
        head = head->next;
    }
    head->data = data;  
}
int max_ll(struct node* head)   // function to find maximum value
{
    int max = -1000000000;
    while(head)
    {
        if(head->data >= max) max = head->data;
        head = head->next;
    }
    return max;
}