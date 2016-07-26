#include <stdio.h>
#include<stdlib.h>
#define MAX_INT 2147483646;

void HeapSort(int*, int);
void BuildHeap(int *, int);
void MaxHeapify(int *, int);

int main(int argc, char* argv[])
{
    int* A = (int*)malloc((argc-1)*sizeof(int));
    int i;
    for(i=0;i<argc-1;i++)
    {
        A[i]=atoi(argv[i+1]);
    }
    HeapSort(A,argc-1);
    for(i=0;i<argc-1;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}
