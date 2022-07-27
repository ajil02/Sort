/*Program to implement Merge Sort*/
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int arr[1000];
void sort (int [], int, int);
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	for (i =0;i<n1;i++)
		L[i]=arr[l+i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i=0;
	j=0;
	k=l;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}	

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}



void sort(int arr[],int l,int r)
{
    int h=r-l;
    if (l<r) 
    {
        int m = l+h/2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int main()
{
   struct timeval t0;
   struct timeval t1;
   float elapsed;
    
   int i,key,ch;
   long n,limit;
   printf("Enter the number of elements:");
   scanf("%ld",&n);
   int arr[n];
   int num=n;
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
   sort(arr,0,n-1);
   gettimeofday(&t1, NULL);
   elapsed = timedifference_msec(t0, t1);
   printf("Sorted List:\n");
   for(j = 0; j < num; j++)
   {
        printf("%d\t",arr[j]);
   }
   printf("Code executed in %f milliseconds.\n", elapsed);
}

