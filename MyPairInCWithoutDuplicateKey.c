

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>


struct MyPair
{
	char key;
	int val;
	struct MyPair * next;
};

struct MyPair * head=NULL;

void sort_ip(char input[])
{
	for(unsigned int i=0;i<strlen(input);i++)
	{
		for(unsigned int j=i+1;j<strlen(input);j++)
		{
			if(input[i]>input[j])
			{
				char temp=input[i];
				input[i]=input[j];
				input[j]=temp;
			}
		}
	}

}

bool isNodePresent(char indexChar)   //it won't accept duplicate char
{
	bool isChar=false;
	struct MyPair * temp=head;
	//printf(" %d ", head);
	while(temp!=NULL)
	{
	//	printf(" %c -> %d ",temp->ch,temp->val);
		if(temp->key==indexChar)
		{
			++temp->val;
			isChar=true;
		}
		temp=temp->next;
	}
	//printf("\n");
	//printf(isChar ? "true":"false");
	//printf("\n");
	return isChar;
}
void createNode(char indexChar)
{
	struct MyPair * newNode=(struct MyPair *)malloc(sizeof(struct MyPair));
	newNode->key=indexChar;
	newNode->val=1;
	newNode->next=head;
	head=newNode;
	//printf(" \n created node for %c = %d ",newNode->ch,newNode->val);
}

void checkCount(char input[])
{
	for(unsigned int i=0;i<strlen(input);i++)
	{
	//	printf("\n=========================\n");
		char getChar=input[i];
	//	printf("\n got the [%d] = %c",i,getChar);
		if(!isNodePresent(getChar))	createNode(getChar);
	}	 
}

void printSortedOP()
{
	//printf("\n\n\n\n\n\n\n\n");
	struct MyPair * temp=head;
	printf("\n==============Data==============\n");
	
	for(struct MyPair * itr1=head;itr1->next!=NULL;itr1=itr1->next)
	{
		for(struct MyPair * itr2=itr1->next;itr2!=NULL;itr2=itr2->next)
		{
			if(itr1->val<itr2->val)
			{
				int amy=itr1->val;
				char ch=itr1->key;
				itr1->val=itr2->val;
				itr1->key=itr2->key;
				itr2->val=amy;
				itr2->key=ch;
			}
		}
	}

	while(temp!=NULL)
	{
		printf("\n %c = %d ",temp->key,temp->val);
		temp=temp->next;
	}
}

int main()
{
	char input[100];
	printf("Enter the string :> ");
	scanf("%s",input);
	
	sort_ip(input);
	printf(" \n sorted -> %s",input);
	
	checkCount(input);
	
	printSortedOP();
}

