#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Maxheap_T *Maxheap_Create(int Size)
{
	Maxheap_T *Root = malloc(sizeof(Maxheap_T));
	if(!Root) {
		return NULL;
	}
	Root->Element = malloc(sizeof(e_t)*Size);
	if(!Root->Element) {
		free(Root);
		return NULL;
	}
	Root->Size= 0;
	Root->Capacity = Size;
	return Root;
}

void PercDown(Maxheap_T *Root, int i)
{
	int Parent, Child;
	e_t TmpVal = Root->Element[i];
	for(Parent=i; Parent*2<Root->Size; Parent=Child) {
		Child = Parent*2;
		if(Child!=Root->Size && Root->Element[Child] <Root->Element[Child+1]) {
			Child++;
		}
		if(Root->Element[Child] < TmpVal) {
			break;
		} 
		Root->Element[Parent] = Root->Element[Child];
	}
}

Maxheap_T *Maxheap_Build(e_t E[], int Len)
{
	Maxheap_T *Root = Maxheap_Create(Len);
	if(!Root) {
		return NULL;
	}

	int i;
	for(i=0; i<Len; i++) {
		Root->Element[i] = E[i];
	}
	Root->Size = Len;

	for(i=Root->Size/2; i>0; i--){
		PercDown(Root, i);
	}
	return Root;
}


