#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------------
// The block of code between the two commented borders is where your solution goes.
typedef struct node node;

struct node{
	int data; // The data stored in this node of Linked list.
	int id; // The id of this node, which is used to uniquely determine this node in the array A.
	struct node *next; // Pointer to the next node in the Linked list.
};
node* findCommonList(node *head1, node *head2){
	if(!(head1 && head2)) return NULL;
	node* temp1 = head1 , *temp2 = head2;
	int c1 = 0 , c2 = 0;
	while(head1)	//counting elements in list 1
	{	
		c1++;
		head1 = head1->next;
	}
	while(head2)	//counting elements in list 2
	{				
		c2++;
		head2 = head2->next;
	}
	int d = c1- c2;	//difference in list
	if(d<0) d = -d;	//absolute value
	node* temp = NULL , *tmp = NULL;
	if(c1>c2) {temp = temp1; tmp = temp2;}	//taking pointer to bigger and smaller list
	else {temp = temp2; tmp = temp1;}
	for (int  i = 0; i < d; i++)			//moving to next node d times in bigger list so now both list after this node have same length
	{
		temp = temp->next;
	}
	while(temp)								// As length of both list is same parallelily checking for common node
	{
		if(temp->id == tmp->id) return temp;
		temp = temp->next;
		tmp = tmp->next;
	}
	return NULL;
}
//------------------------------------------------------------------------------------------

void printList(node *head){
	node *curr = head;
	int len = 0;
	while(curr!=NULL){
		len++;
		curr = curr->next;
	}
	curr = head;
	printf("%d ",len );
	while(curr!=NULL){
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	struct node **head1 = malloc(sizeof(struct node*));
	struct node **head2 = malloc(sizeof(struct node*));
	char tmp = 'a';
	int val;
	int t;
	scanf("%d\n", &t);
	int *a = malloc(sizeof(int)*t);
	int i = 0;
	do
	{
		scanf("%d%c", &val, &tmp);
		a[i++] = val;
	} while (i < t);
	struct node *curr = *head1;
	struct node *prev = NULL;
	do
	{
		scanf("%d%c", &val, &tmp);
		curr = malloc(sizeof(struct node));
		curr->id = val;
		curr->data = a[val-1];
		if(prev) prev->next = curr;
		else *head1 = curr;
		prev = curr;
		curr = curr->next;
	} while (tmp!='\n');
	curr = *head2;
	prev = NULL;
	do
	{
		scanf("%d%c", &val, &tmp);
		curr = malloc(sizeof(struct node));
		curr->id = val;
		curr->data = a[val-1];
		if(prev) prev->next = curr;
		else *head2 = curr;
		prev = curr;
		curr = curr->next;
	} while (tmp!='\n');
	node* commonNode = findCommonList(*head1, *head2);
	printList(commonNode);
	return 0;
}