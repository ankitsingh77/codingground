#include <stdio.h>
#include<stdlib.h>

void selectionSort(int*, int);

int main(int argc, char* argv[])
{
    int* A = (int*)malloc((argc-1)*sizeof(int));
    int i;
    for(i=0;i<argc-1;i++)
    {
        A[i]=atoi(argv[i+1]);
    }
    selectionSort(A,argc-1);
    for(i=0;i<argc-1;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}

void selectionSort(int *A, int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            A[min]^=A[i];
            A[i]^=A[min];
            A[min]^=A[i];
        }
    }
}

