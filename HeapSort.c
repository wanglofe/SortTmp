#include <stdio.h>
#include <stdlib.h>

void PercDown(int A[], int i, int N);
void HeapSort(int A[], int N);

static void print(int A[], int N)
{
	int i;
	for(i=0; i<N;i++) {
		printf("%d ", A[i]);
	}
	putchar('\n');
}

int main(int argc, char **argv)
{
	int A[] = {1112,33,53,6,832,239,54,232,546,9191};
	int N = sizeof(A)/sizeof(int);
	print(A, N);
	HeapSort(A, N);
	print(A, N);

	return 0;

}

// Store from A[0], no solider exits
#define LeftChild(i) (2*(i)+1)
void PercDown(int A[], int i, int N)
{
	int Child;
	int Parent;
	int Tmp = A[i];
	for(Parent=i; LeftChild(Parent)<N;Parent=Child) {
		Child=LeftChild(Parent);
		if(Child!=N-1 && A[Child+1]>A[Child])
		       Child++;
		if(Tmp>A[Child])	
			break;
		else
			A[Parent]=A[Child];	
	
	}
	A[Parent]=Tmp;
}

static void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapSort(int A[], int N)
{
	int i;
	for(i=N/2;i>=0; i--)
		PercDown(A, i, N);
	for(i=N-1; i>0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}


