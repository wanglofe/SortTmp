#include <stdio.h>
#include <stdlib.h>

void QuickSort(int A[], int N);

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
	QuickSort(A, N);
	print(A, N);

	return 0;

}

void quick_sort(int A[], int left, int right);
void QuickSort(int A[], int N)
{
	quick_sort(A, 0, N);
}
#if 0
void quick_sort(int A[], int left, int right)
{
	int pivot=A[left];
	if(left<right){
		for(;;){
			while(left<right && A[right]>pivot)
				right--;
			if(left<right)
				Swap(&A[left], &A[right]);
			while(left<right && A[left]<pivot)
				left++;
			if(left<right)
				Swap(&A[left], &A[right]);
		}

	}
}
#endif
void quick_sort(int A[], int left, int right)
{
	int i=left, j=right;
	int pivot = A[i];
	if(i<j) {
		while(i!=j) {
			while(i<j && A[j]>pivot)
				j--;
			if(i<j)
				A[i] = A[j];
			while(i<j && A[i] < pivot)
				i++;
			if(i<j)
				A[j] = A[i];
		}
		A[i]=pivot;
		quick_sort(A, 0, i-1);
		quick_sort(A, i+1, right);
	}
}
