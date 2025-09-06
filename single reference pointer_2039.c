//Roll no: 2039.
// Name: Akash Mahadev Mali.
//Experiment no:2 Singly Linked List (One external reference pointer).
#include<stdio.h>
#include<stdlib.h>
void Createatstart();
void Createatend();
void CreateatLocation();
void Deleteatstart();
void Deleteatend();
void DeleteatLocation();
void Traverse();
struct node
{
	int data;
	struct node*next;
};
typedef struct node NODE;
NODE *start=NULL,*p,*q;

int main()
{
	int ch;
	do
	{
		printf("\n\n 1.Create at start.\n 2.Create at end.\n 3.Create at given location.\n 4.Delete at start.\n 5.Delete at end.\n 6.Delete at given location.\n 7.Traverse.\n 8.Exit.\n\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: Createatstart();
			break;
			case 2: Createatend();
			break;
			case 3: CreateatLocation();
			break;
			case 4: Deleteatstart();
			break;
			case 5: Deleteatend();
			break;
			case 6: DeleteatLocation();
			break;
			case 7: Traverse();
			break;
			case 8: break;
			default: printf("Invalid input!");
		}	
	}while(ch!=8);
	return 0;
}


void Createatstart()
{
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data:");
	scanf("%d",&p->data);
	if(start==NULL)
	{
	    p->next=NULL;
		start=p;	
	}
	else
	{
		p->next=start;
		start=p;
	}
}


void Traverse()
{
	if(start==NULL)
	{
		printf("The linked list is empty!");
	}
	else
	{
		p=start;
		printf("\n");
		while(p!=NULL)
		{
			printf("%d",p->data);
			p=p->next;
			printf("->");
		}
		printf("NULL\n");
	}
}


void Createatend()
{
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data:");
	scanf("%d",&p->data);
	if(start==NULL)
	{
		p->next=NULL;
		start=p;
	}
	else 
	{
	q=start;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	p->next=NULL;
		
	}
}


void CreateatLocation()
{
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data:");
	scanf("%d",&p->data);
	int loc,i;
	printf("Enter the location:");
	scanf("%d",&loc);
	if(start==NULL)
	{
		if(loc==1)
		{
			p->next=NULL;
			start=p;
		}
		else
		{
			printf("\nInvalid Location!");
		}
	}
	else
	{
		if(loc==1)
		{
			p->next=start;
			start=p;
		}
		else
		{
			i=1;
			q=start;
			while(i<loc-1 && q!=NULL)
			{
				q=q->next;
				i++;
			}
			if(q!=NULL)
			{
				p->next=q->next;
				q->next=p;
			}
			else
			{
				printf("\nInvalid location!");
			}
		}
	}
}

void Deleteatstart()
{
	if(start==NULL)
	{
		printf("Linked list is empty!Delete cannot be performed.");
	}
	else
	{
		p=start;
		start=p->next;
		printf("%d is deleted!",p->data);
		free(p);
	}
	
}
void Deleteatend()
{
	if(start==NULL)
	{
		printf("Linked list is empty! delete cannot be performed.");
	}
	else if(start->next==NULL)
	{
		p=start;
		start=NULL;
		printf("%d is deleted!",p->data);
		free(p);
		
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		printf("%d is deleted!",p->data);
		q->next=NULL;
		free(p);
	}
}

void DeleteatLocation()
{
	int loc,i;

	if(start==NULL)
	{
		printf("The linked list is empty! Delete cannot be performed.");
	}
	else
	{	
	printf("Enter the location:");
	scanf("%d",&loc);
		if(loc==1)
		{
			p=start;
			start=p->next;
			printf("%d is deletsd ",p->data);
			free(p);
		}
		else
		{
			i=1;
			p=start;
			while(i<loc && p!=NULL)
			{
				q=p;
				p=p->next;
				i++;
			}
			if(p!=NULL)
			{
				q->next=p->next;
				printf("%d is deleted.",p->data);
				free(p);
			}
			else
			{
				printf("\nInvalid location!");
			}
		}
	}
}

