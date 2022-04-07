#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void chuyenMang(int t, int w, long long a, long long b[])
{
    int k;
    for(int i =1; i<=t; i++)
    {
        k=a/(pow(2,(t-i)*w));
        if(k==0)
        {
            b[i]=0;
            printf("%I64d\t", b[i]);
            continue;
        }
        else
        {
            b[i]=k;
            printf("%I64d\t", b[i]);
            a=a-k*(pow(2,(t-i)*w));
        }

    }
}
void phepCong(int t, int w, long long m[], long long n[], long long c[])
{
    int e;
    c[t]=(m[t]+n[t])%((long long)pow(2, w));
    if((m[t]+n[t])>=0 && (m[t]+n[t])<=(pow(2, w)))
    {
        e=0;
    }
    else
    {
        e=1;
    }
    for(int i=t-1; i>0; i--)
    {
        c[i]=(m[i]+n[i]+e)%((long long)pow(2, w));
        if((m[i]+n[i]+e)>=0 && (m[i]+n[i]+e)<=(pow(2, w)))
        {
            e=0;
        }
        else
        {
            e=1;
        }
    }
    printf("(%d,[", e);
    for(int i=1; i<=t-1; i++)
    {
        printf("%5I64d", c[i]);
    }
    printf("%5I64d])", c[t]);
}
int main()
{
    int t, w;
    long long a, b, p;
    printf("Nhap w = \n");
    scanf("%d", &w);
    printf("Nhap 2 so a, b\n");
    scanf("%I64d %I64d", &a, &b);
    printf("Nhap truong p = \n");
    scanf("%I64d", &p);
    long int m=ceil(log(p)/log(2)+1);
    t=(m/w);
    long long u[t], v[t], c[t];
    chuyenMang(t, w, a, u);
    printf("\n");
    chuyenMang(t, w, b, v);
    printf("\n");
    phepCong(t, w, u, v, c);
    return 0;
}
