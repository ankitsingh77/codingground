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
    MergeSort(A,0,argc-2);
    for(i=0;i<argc-1;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}

void MergeSort(int *A,int p, int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

void Merge(int *A, int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int *L = (int*)malloc((n1+1)*sizeof(int));
    int *R = (int*)malloc((n2+1)*sizeof(int));
    int i,j;
    printf("n1= %d, n2 = %d \n",n1,n2);
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];
        printf("L[%d] = %d \n",i,L[i]);
    }
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
        printf("R[%d] = %d \n",j,R[j]);
    }
    L[n1]=MAX_INT;
    R[n2]=MAX_INT;
    int k;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
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
        printf("A[%d] = %d \n",k,A[k]);
    }
    free(L);
    free(R);
}
