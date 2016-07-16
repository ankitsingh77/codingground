#include <stdio.h>
#include<stdlib.h>

void Bubblesort(int *,int);
int main(int argc, char *argv[])
{
    //printf("Hello, World!\n");
    int* A = (int*)malloc((argc-1)*sizeof(int));
    int i;
    for(i=0;i<argc-1;i++)
    {
        A[i]=atoi(argv[i+1]);
    }
    Bubblesort(A,argc);
    for(i=0;i<argc-1;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}

void Bubblesort(int* A, int n)
{
    int i,j,swapped=1;
    for(i=n-1;i>=0&&swapped ==1;i--)
    {
        swapped = 0;
        for(j=0;j<i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                A[j]^=A[j+1];
                A[j+1]^=A[j];
                A[j]^=A[j+1];
                swapped = 1;
            }
        }
    }
}

