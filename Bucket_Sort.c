#include <stdio.h>
#include <stdlib.h>

void Print(int A[], int N);
int FindMax(int A[], int N);
void bucket_sort(int A[], int N, int max);
void Bucket_Sort(int A[], int N);

void main(void)
{
	int A[] = {2,4,6,2,2,6,7,3,3,6,7,8,2,9,6,5,4,3,3,5,88};
	int N = sizeof(A)/sizeof(int);
	Print(A, N);
	Bucket_Sort(A, N);	
	Print(A, N);
}

void Bucket_Sort(int A[], int N)
{
	bucket_sort(A, N, FindMax(A, N));
}

void Print(int A[], int N)
{
	int i;
	for(i=0; i<N; i++)
		printf("%d ", A[i]);
	putchar('\n');
}

int FindMax(int A[], int N)
{
	int Max = A[0];
	int i;
	for(i=1; i<N; i++)
		if(Max<A[i])
			Max=A[i];
	return Max+1;
}

void bucket_sort(int A[], int N, int max)
{
	int *bucket = calloc(sizeof(int)*max, 1);
	if(!bucket)	return;

	int i;
	for(i=0; i<N; i++)
		bucket[A[i]]++;
	int j;
	for(i=0,j=0; i<max; i++)
		while(bucket[i]--)
			A[j++] = i;
	free(bucket);
}


