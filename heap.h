#ifndef __HEAP_H__
#define __HEAP_H__

typedef int e_t;

typedef struct heap {
	e_t *Element;
	int Size;
	int Capacity;	
} Maxheap_T;

extern void PercDown(Maxheap_T *Root, int i);
extern Maxheap_T *Maxheap_Create(int Size);
extern Maxheap_T *Maxheap_Insert(Maxheap_T *Root, e_t Value);
extern e_t Maxheap_Delete(Maxheap_T *Root);
extern Maxheap_T *Maxheap_Build(e_t Element[], int Len);

#endif
