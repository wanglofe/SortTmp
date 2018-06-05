#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void print(int A[],int N);
void Selection_Sort(int A[],int N);
void Heap_Sort(int A[], int N);

int main(int argc, char **argv)
{
	int A[] = {3,1,4,766,1323,42432,756534,332232,348}; 
	int B[] = {3,1,4,766,1323,42432,756534,332232,348}; 
	int N = sizeof(A)/sizeof(int);
	Selection_Sort(A, N);
	print(A, N);
	Heap_Sort(B, N);
	print(B, N);

}

void print(int A[], int N)
{
	int i;
	for(i=0; i<N; i++) {
		printf("%d ", A[i]);
	}
	putchar('\n');
}

static void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Selection_Sort(int A[], int N)
{
	int i, j;
	for(i=0; i<N; i++) {
		for(j=i; j<N; j++) {
			if(A[i] > A[j])
				Swap(&A[i], &A[j]);
		}
	}
}

void Heap_Sort(int A[], int N)
{
	Maxheap_T *Root = Maxheap_Build(A, N);
	
	int i;
	for(i=N-1; i>0; i--) {
		Swap(&Root->Element[0], &Root->Element[i]);
		PercDown(Root, i-1);	
	}
}




