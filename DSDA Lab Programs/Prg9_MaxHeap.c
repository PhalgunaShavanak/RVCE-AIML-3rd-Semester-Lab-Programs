#includ	e <stdio.h>
int heap[100],size=0;

void heapify(int i)
{
	int largest,left,right;
	largest=i;
	left=2*i+1;
	right=2*i+2;
	
	if(left<size && heap[left]>heap[largest]) largest = left;
	
	if(right<size && heap[right]>heap[largest]) largest = right;
	
	if(largest != i)
	{
		heap[largest] += heap[i]-(heap[i]=heap[largest]);
		heapify(largest);
	}
}

void main()
{
	int x,i;
	while(1)
	{
		printf("Enter new element or -1 to quit:");
		scanf("%d",&x);
		if(x==-1) break;.
		
		if(size==0) heap[size++]=x;
		
		else
		{
			heap[size++]=x;
			for(i =size/2 - 1;i>=0;i--) heapify(i);
		}
	}
	for(i=0;i<size;i++) printf("%d ",heap[i]);
}