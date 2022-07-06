#include<stdio.h>
#include<stdlib.h>
int size=4,top=-1;


struct node
{
	int data;
	struct node *next;
};


struct node *head=NULL,*pos=NULL,*tail=NULL,*temp;

//to check if stack is full
int isfull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}

//to check if stack is empty
int isempty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

//to insert element into stack
void push(int val)
{
	if(isfull())
	{
		printf("\nOverflow");
	}
	else if(isempty())
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=val;
		tail=head;
		printf("\n%d pushed",head->data);
		top++;
	}
	else
	{	
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=val;
		temp->next=head;
		head=temp;
		printf("\n%d pushed",head->data);
		top++;
	}
	
	
}

//to delete element from stack
void pop()
{
	if(isempty())
	{
		printf("Underflow");
	}
	else
	{
		temp=head;
		head=head->next;
		temp->next=NULL;
		printf(" %d popped",temp->data);
		free(temp);
		top--;
	}
}

//to display elements
void display()
{	
	int j,i;
	
	if(isempty())
	{
		printf("Empty Stack");
	}
	else
	{
		
		pos=head;
		for(i=0;i<=top;i++)
		{
			printf("\n%d",pos->data);
			pos=pos->next;
		}
		
	}
}

//to find the top of stack
void findtop()
{
	printf("\ntop position=%d\n",top);
	if(head==NULL)
		printf("top value=NULL");
	else
		printf("top value=%d",head->data);
}

void main()
{
	int ch,entry;
	
	printf("Enter Stack Size :");
	scanf("%d",&size);
	
	while(1)
	{
		printf("\n\n1:PUSH\n2:POP\n3:DISPLAY\n4:Is Stack Empty\n5:Is Stack Full\n6:Find top\n7:Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter data :");
				scanf("%d",&entry);
				push(entry);
				break;
			}
			
			case 2:
			{
				pop();
				break;
			}
			
			case 3:
			{
				display();
				break;
			}
			
			case 4:
			{
				if(isempty())
					printf("\nStack is Empty");
				else
					printf("\nStack is not Empty ");
				break;
			}
			
			case 5:
			{
				if(isfull())
					printf("\nStack is Full");
				else
					printf("\nStack is not Full ");
				break;
			}
			
			case 6:
			{
				findtop();
				break;
			}
			
			case 7:
			{
				printf("Exiting...");
				exit(0);
			}
			
			default:
			{
				printf("Invalid choice");
			}
		}
	}
}
