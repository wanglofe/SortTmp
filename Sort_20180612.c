#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b);
void Print(int A[], int N);
void PercDown(int A[], int i, int N);
void quick_sort(int A[], int left, int right);
void Bubble_Sort(int A[], int N);
void Insert_Sort(int A[], int N);
void Shell_Sort(int A[], int N);
void Select_Sort(int A[], int N);
void Heap_Sort(int A[], int N);
void Quick_Sort(int A[], int N);

//int main(int argc, char **argv)
void main(void)
{
	int A[] = {9,8,7,6,5,4,3,2,1,0};
	int B[] = {9,8,7,6,5,4,3,2,1,0};
	int C[] = {9,8,7,6,5,4,3,2,1,0};
	int D[] = {9,8,7,6,5,4,3,2,1,0};
	int F[] = {9,8,7,6,5,4,3,2,1,0};
	int E[] = {9,8,7,6,5,4,3,2,1,0};
	int N = sizeof(A)/sizeof(int);
	Print(A, N);
	Bubble_Sort(A, N);
	Print(A, N);
	Insert_Sort(B, N);
	Print(B, N);
	Insert_Sort(C, N);
	Print(C, N);
	Insert_Sort(D, N);
	Print(D, N);
	Heap_Sort(F, N);
	Print(F, N);
	Quick_Sort(E, N);
	Print(E, N);
}

void Bubble_Sort(int A[], int N)
{
	int i, j;
	for(i=N-1; i>0; i--){
		for(j=0; j<i; j++){
			if(A[j] > A[j+1])
				Swap(&A[j], &A[j+1]);
		}
	}
}

void Insert_Sort(int A[], int N)
{
	int i, j;
	int Tmp;
	for(i=1; i<N; i++){
		Tmp = A[i];
		for(j=i; j>0;j--) {
			if(Tmp<A[j-1])	
				A[j]=A[j-1];	
		}
		A[j]=Tmp;
	}
}

void Shell_Sort(int A[], int N)
{
	int i, j, gap;
	int Tmp;
	for(gap=N/2; gap>0; gap/=2) {
		for(i=gap; i<N; i++){
			Tmp = A[i];
			for(j=i; j>gap; j-=gap) {
				if(Tmp < A[j-gap])
					A[j] = A[j-gap];
			}
		}
		A[j]=Tmp;
	}
}

void Select_Sort(int A[], int N)
{
	int i, j;
	for(i=0; i<N; i++) {
		for(j=i+1; j<N-1; j++) {
			if(A[i] > A[j])	
				Swap(&A[i], &A[j]);
		}
	}
}

void Heap_Sort(int A[], int N)
{
	int i;
	for(i=N/2-1; i>=0; i--)
		PercDown(A, i, N);
	for(i=N-1; i>0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}	
}

void Quick_Sort(int A[], int N)
{
	quick_sort(A, 0, N);
}

//---------------------------------------------
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int A[], int N)
{
	int i;
	for(i=0; i<N; i++) {
		printf("%d ", A[i]);
	}
	putchar('\n');
}

void PercDown(int A[], int i, int N)
{
	int Parent, Child;
	int Tmp=A[i];
	for(Parent=i; Parent*2+1<N; Parent=Child) {
		Child=Parent*2+1;
		if(Child!=N-1 && A[Child] < A[Child+1])
			Child++;
		if(Tmp>A[Child]) break;
		else	A[Parent]=A[Child];
	}
	A[Parent]=Tmp;
}

// stack smashing detected***
void quick_sort(int A[], int left, int right)
{
	int i=left, j=right;
	int pivot=A[i];
	if(left>right)	return;
	while(i<j) {
		while(i<j && A[j]>pivot)	j--;
		if(i<j)	A[i]=A[j];
		while(i<j && A[i]<pivot)	i++;
		if(i<j) A[j]=A[i];
	}
	A[i]=pivot;
	quick_sort(A, 0, i-1);
	quick_sort(A, i+1, right);
}
