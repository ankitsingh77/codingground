#include <stdio.h>
#include<stdlib.h>
#define MAX_INT 2147483646;

void MergeSort(int*, int, int);
void Merge(int*,int,int,int);

int main(int argc, char* argv[])
{
    int* A = (int*)malloc((argc-1)*sizeof(int));
    int i;
    for(i=0;i<argc-1;i++)
    {
        A[i]=atoi(argv[i+1]);
    }
    MergeSort(A,0,argc-1);
    for(i=0;i<argc-1;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}

void MergeSort(int *A,int p, int r)
{
    int q=(p+r)/2;
    if(q>0)
    {
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void Merge(int *A, int p, int q, int r)
{
    int n1=q-p;
    int n2=r-q;
    int *L = (int*)malloc((n1+1)*sizeof(int));
    int *R = (int*)malloc((n2+1)*sizeof(int));
    int i,j;
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    L[n1]=MAX_INT;
    R[n2]=MAX_INT;
    int k;
    for(k=p;k<r;k++)
    {
        i=0;
        j=0;
        if(L[i]<R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    free(L);
    free(R);
}
