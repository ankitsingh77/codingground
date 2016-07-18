
#include <stdio.h>
#include<stdlib.h>

void insertionSort(int*, int);

int main(int argc, char* argv[])
{
    int* A = (int*)malloc((argc-1)*sizeof(int));
    int i;
    for(i=0;i<argc-1;i++)
    {
        A[i]=atoi(argv[i+1]);
    }
    insertionSort(A,argc-1);
    for(i=0;i<argc-1;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}

void insertionSort(int *A, int n)
{
    int i,j;
    int key;
    for(i=2;i<n;i++)
    {
        key = A[i];
        j=i-1;
        while(A[j]>key)
        {
            A[j+1]= A[j];
            j= j-1;
        }
        A[j+1] = key;
    }
}
