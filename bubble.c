#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr[100];

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;
    int n;
    printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	
	int i,key,ch,pos;
	
	int j,x,y,temp;
	gettimeofday(&t0, NULL);
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i] = rand()%100);
	}
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("Random Generation code executed in %f milliseconds.\n", elapsed);
    printf("\n");
    
    gettimeofday(&t0, NULL);
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
    gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
    printf("Sorted List:\n");
	for(j = 0; j < n; j++)
	{
		printf("%d\t",arr[j]);
	}
   printf("Code executed in %f milliseconds.\n", elapsed);
}
