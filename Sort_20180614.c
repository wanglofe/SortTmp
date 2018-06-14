#include <stdio.h>
#include <stdlib.h>

void Print(int A[], int N);
void Swap(int *a, int *b);
void Bubble_Sort(int A[], int N);
void Insert_Sort(int A[], int N);
void Shell_Sort(int A[], int N);
void Select_Sort(int A[], int N);
void PercDown(int A[], int i, int N);
void Heap_Sort(int A[], int N);
void quick_sort(int A[], int left, int right);
void Quick_Sort(int A[], int N);
int Findmax(int A[], int N);
void bucket_sort(int A[], int N, int max);
void Bucket_Sort(int A[], int N);

int main(int argc, char **argv)
{
	int A[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int B[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int C[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int D[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int E[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int F[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int G[] = {8,7,5,4,3,2,1,0,11,44,22,44,77,23};
	int N = sizeof(A)/sizeof(int);
	Print(A, N);
	Bubble_Sort(A, N);
	Print(A, N);
	Insert_Sort(B, N);
	Print(B, N);
	Select_Sort(C, N);
	Print(C, N);
	Shell_Sort(D, N);
	Print(D, N);
	Heap_Sort(E, N);
	Print(E, N);
	Quick_Sort(F, N);
	Print(F, N);
	Bucket_Sort(G, N);
	Print(G, N);
}

void Bubble_Sort(int A[], int N)
{
	int i,j;
	for(i=N; i>=0; i--)
		for(j=0; j<i-1; j++)
			if(A[j] > A[j+1])
				Swap(&A[j], &A[j+1]);

}

void Insert_Sort(int A[], int N)
{	
	int i, j;
	int tmp;
	for(i=0; i<N; i++) {
		tmp = A[i];
		for(j=i; j>0; j--) {
			if(A[j-1] > tmp)
				A[j] = A[j-1];
			else break;
		}
		A[j] = tmp;
	}
}

void Select_Sort(int A[], int N)
{
	int i, j;
	for(i=0; i<N; i++) {
		for(j=i+1; j<N; j++){
			if(A[i]>A[j])
				Swap(&A[i],&A[j]);
		}
	}
}

void Shell_Sort(int A[], int N)
{
	int i, j, gap, tmp;
	for(gap=N/2; gap>0; gap/=2) {
		for(i=gap; i<N; i++) {
			tmp=A[i];
			for(j=i; j>=gap; j-=gap) {
			//for(j=i; j>gap; j-=gap) {
				if(tmp<A[j-gap])
					A[j]=A[j-gap];
				else break;
			}
			A[j] = tmp;
		}
	}
}

void Heap_Sort(int A[], int N)
{
	int i;
	for(i=N/2; i>=0; i--)// the same
//	for(i=N/2-1; i>=0; i--)
		PercDown(A, i, N);
	for(i=N-1; i>0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

void Quick_Sort(int A[], int N)
{
	quick_sort(A, 0, N-1);
}

void quick_sort(int A[], int left, int right)
{
	int i=left, j=right;
	int pivot=A[i];
	if(left>right) return;
	while(i!=j) {
		while(i<j && pivot<=A[j]) j--;
		if(i<j) A[i]=A[j];
		while(i<j && pivot>A[i]) i++;
		if(i<j) A[j]=A[i];
	}
	A[i]=pivot;
	quick_sort(A, 0, i-1);
	quick_sort(A, i+1, right);
}

void Bucket_Sort(int A[], int N)
{
	bucket_sort(A, N, Findmax(A, N));
}

void bucket_sort(int A[], int N, int max)
{
	int *bucket = calloc(sizeof(int)*max, 1);
	if(!bucket) return;
	int i;
	for(i=0; i<N; i++)
		bucket[A[i]]++;
	int j;
	for(i=0,j=0; j<max; j++)
		while(bucket[j]--)
			A[i++]=j;
	free(bucket);
}

void Print(int A[], int N)
{
	int i;
	for(i=0; i<N;i++)
		printf("%d ", A[i]);
	putchar('\n');
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Findmax(int A[], int N)
{
	int max = A[0];
	int i;
	for(i=0; i<N; i++)
		if(A[i]>max)
			max = A[i];
	return max+1;
}

void PercDown(int A[], int i, int N)
{
	int Parent, Child, Tmp;
	Tmp = A[i];
	for(Parent=i; Parent*2+1<N; Parent=Child) {
		Child=Parent*2+1;
		if(Child!=N-1 && A[Child]<A[Child+1]) 
			Child++;
		if(Tmp > A[Child]) break;
		else	A[Parent]=A[Child];
	}
	A[Parent]=Tmp;
}
