//thuat toán Miller Rabin: Kiểm tra xem liệu n có là số nguyên tố hay không?
//Input: số nguyên lẻ n>=3 và tham số an toàn t>=1
#include <stdio.h>
#include <stdlib.h>
void phanTich(int n, int*s, int *t)
{
    int k=1, m=n-1;
    int r=m/2;
    // printf("%d", r);
    while(r%2==0)
    {
        r=r/2;
        k++;
    }
    *s=k;
    *t=r;
}
int binary(int n, int a[])
{
    int j=0;
    for(int i=n; n>0; n=n/2)
    {
        a[j] = n % 2;
        j++;
    }
    return j;
}
int nhanBinhPhuongLap(int a,int k,  int n )
{
    int b, A;
    b=1;
    if(k==0)
    {
        return b;
    }
    A=a;
    int arrK[100];
    int t=binary(k, arrK);
    if(arrK[0]==1)
    {
        b=a;
    }
    for(int i=1; i<=t; i++)
    {
        A=A*A %n;
        if(arrK[i]==1)
        {
            b=A*b%n;
        }
    }
    return b;
}
int xuLy ( int t, int r, int n, int s)
{
    int a;
    for(int i=1; i<=t; i++)
    {
        printf("Nhap so a bat ki 2<= a <= n-2:\n");
        scanf("%d", &a);
        int y= nhanBinhPhuongLap(a, r, n);
        if(y!=1 &&y !=n-1)
        {
            int j=1;
            while(j<=s-1 &&y!=n-1)
            {
                y=y*y %n;
                if(y==1)
                {
                    return 0;
                }
                j++;
            }
            if(y!=n-1)
            {
                return 0;
            }
        }
        return 1;

    }
}
int main()
{
    int n, s, r, t;
    printf("Nhap so le n:\n");
    scanf("%d", &n);
    phanTich(n, &s, &r);
    printf("%d %d\n", s, r);
    printf("Nhap so T:\n");
    scanf("%d", &t);
    if(xuLy(t, r, n, s)==1)
    {
        printf("%d la so nguyen to\n",n);

    }
    else
    {
        printf("%d la hop so \n",n);
    }

    return 0;
}
