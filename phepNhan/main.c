#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 500
long long w,t,p;
void numToArr(long long a,long long arr[])
{
    long long i;
    for(i=t-1; i>=0; i--)
    {
        arr[i]=a/pow(2,i*w);
        a-=arr[i]*pow(2,i*w);
    }
}
void inputArr(long long arr[])
{

    long long i;
    for(i=t-1; i>=0; i--)
    {
        scanf("%d",&arr[i]);
    }
}
void output(long long arr[])
{
    long long i;
    for(i=t-1; i>=0; i--)
    {
        printf("%d ",arr[i]);
    }
}
void mul(long long arr[],long long brr[],long long crr[])
{
    long long i,j,UV,u;
    for(i=0; i<t; i++)
    {
        u=0;
        for(j=0; j<t; j++)
        {
            UV=crr[i+j]+arr[i]*brr[j]+u;
            u=UV/pow(2,w);
            crr[i+j]=UV%(long long)pow(2,w);//=v
            crr[i+t]=0;
        }
    }
}
int main()
{
    long long arr[MAX],brr[MAX],crr[MAX],a,b,m;
    printf("nhap p,w,a,b:");
    scanf("%d %d %d %d",&p,&w,&a,&b);
    m=ceil(log2(p));
    t=ceil((double)m/w);
   // inputArr(arr);
     numToArr(a,arr);
    output(arr);
    printf("\n");
 //  inputArr(brr);
    numToArr(b,brr);
    output(brr);
    printf("\n");
    mul(arr,brr,crr);
    long long i;
    for(i=2*t-1; i>=0; i--)
    {
        printf("%d ",crr[i]);
    }
    printf("\n");
}
