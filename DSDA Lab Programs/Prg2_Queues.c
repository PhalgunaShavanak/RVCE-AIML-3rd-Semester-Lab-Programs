#include<stdio.h>
#include<stdlib.h>
#define MAX 500

int front = -1;
int rear = -1;

struct request
{
    int num;
    int mem;
};

struct request req[MAX];

void insert(int n, int m)
{
	if(rear == MAX-1)
	{
		printf("Queue Overflow");
	}
	else
	{
		if(front == -1)
		{
			front = 0;
		}
	rear  = rear + 1;
	req[rear].num = n;
	req[rear].mem = m;
	}
}

struct request delete()
{
	if(front == -1 || front>rear)
	{
		printf("Queue Underflow");
		front = -1;
		rear = -1;
	}
	else
	{
		return req[front++];
	}
}

int main()
{
	int memory=3000;
	int numin,memin;
	int noreq;
	struct request temp;
	printf("Enter the number of requests :");
	scanf("%d",&noreq);
	for(int i = 0;i<noreq;i++)
	{
		numin = 1000+(rand()%9000);
		memin = 100+(rand()%900);
		insert(numin,memin);
		printf("The process %d has been allocated %d bytes\n",numin,memin);

	}
	while(front <= rear)
	{
		temp=delete();
		if(memory>=temp.mem)
		{
			memory = memory - temp.mem;
			printf("The process %d has been called and %d bytes of memory is left\n",temp.num, memory);

		}
		else
		{
			printf("The process %d couldn't be processed and remaining memory is %d bytes\n",temp.num,memory);
		}
	}
	return 0;
}
