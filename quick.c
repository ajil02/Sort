/*Program to implement Quick sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0,struct timeval t1)
{
	return(t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void display(int n,int arr[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
}

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}	

int partition(int arr[], int low, int high)
{
	int pivot=arr[high];
	int i=low,j;
	
	for(j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[high]);
	return i;
}

void quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pindex=partition(arr,low,high);
		quicksort(arr,low,pindex-1);
		quicksort(arr,pindex+1,high);
	}
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int x,n,i,j=0,temp;
	
	printf("Enter number of elements ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	
	printf("\n The unsorted elements are :");
	display(n,arr);
	
	gettimeofday(&t0, NULL);
	
	quicksort(arr,0,n-1);
	
	printf("\n The sorted elements are :");
	display(n,arr);
	
	gettimeofday(&t1, NULL);
	elapsed=timedifference_msec(t0,t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
}
