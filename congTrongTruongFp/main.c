#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void chuyenMang(long int t, long int w, long long a, long long b[])
{
    int k;
    for(long int i =1; i<=t; i++)
    {
        k=a/(pow(2,(t-i)*w));
        if(k==0)
        {
            b[i]=0;
            printf("%lld\t", b[i]);
            continue;
        }
        else
        {
            b[i]=k;
            printf("%lld\t", b[i]);
            a=a-k*(pow(2,(t-i)*w));
        }

    }
}

long long phepCong(int e,long int t, long int w, long long m[], long long n[], long long c[])
{
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
    return e;
}

long long phepTru(int e,long int t, long int w, long long m[], long long n[], long long c[])
{
    c[t]=(m[t]-n[t])%((long long)pow(2, w));
    if(c[t]<0)
    {
        c[t]=(pow(2, w))+c[t];
    }
    if((m[t]-n[t])>=0 && (m[t]-n[t])<=(pow(2, w)))
    {
        e=0;
    }
    else
    {
        e=1;

    }
    for(int i=t-1; i>0; i--)
    {
        c[i]=(m[i]-n[i]-e)%((long long)pow(2, w));
        if(c[i]<0)
        {
            c[i]=(pow(2, w))+c[i];
        }
        if((m[i]-n[i]+e)>=0 && (m[i]-n[i]+e)<=(pow(2, w)))
        {
            e=0;
        }
        else
        {
            e=1;
        }
    }
    return e;
}
int soSanh(int maTran_c[], int maTran_p[], int t)
{
    for(int i = t-1 ; i >= 0 ; i++)
    {
        if(maTran_c[i] > maTran_p[i])
        {
            return 1;
        }
        if(maTran_c[i] < maTran_p[i])
        {
            return 0;
        }
    }
    return 0;
}
void print_array( long long a[], long long e, long int w, long int t)
{
    printf("(%d,[", e);
    for(int i=1; i<=t-1; i++)
    {
        printf("%5lld", a[i]);
    }
    printf("%5lld])", a[t]);
}
int main()
{
    long long p, a, b, e, e1, e2, x;
    printf("Nhap so modulo p:\n");
    scanf("%I64d", &p);
    printf("Nhap 2 so a, b:\n");
    scanf("%I64d", &a);
    scanf("%I64d", &b);
    long int w;
    printf("Nhap w = \n");
    scanf("%d", &w);
    long int m=ceil(log(p)/log(2));
    long int t=(m/w)+1;
    long long a1[t], b1[t], c[t], p1[t], p2[t];
    printf("chuyen so a thanh mang:\n");
    chuyenMang(t, w, a, a1);
    printf("\n");
    printf("chuyen so b thanh mang:\n");

    chuyenMang(t, w, b, b1);
    printf("\n");
    e= phepCong(e1, t, w, a1, b1, c);
    printf("\n");
    printf("chuyen so p thanh mang:\n");
    chuyenMang(t, w, p, p1);
    printf("\n");
    printf("Ket qua:\n");
    if(e==1|| soSanh(c, p1, t))
    {
        e2=phepTru(e2, t, w, c, p1, p2);
        print_array(p2, e2, w, t);
    }
    else
    {
        e1=phepCong(e1, t, w, a1, b1, c);
        print_array(c, e1, w, t);
    }
    return 0;
}
//2634067223
//2835415104
