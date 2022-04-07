//thuật toán vét cạn
#include <stdio.h>
#include <stdlib.h>
int nhap(char a[])
{
    int i=0;
    char c;
    while(c!='\n')
    {
        scanf("%c", &c);
        a[i]=c;
        i++;
    }
    return i;
}
void inMang(char a[], int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%c", a[i]);
    }
}
int vetCan(char a[],int n, char b[], int m)
{
    int *F,k=0;
    int lap=0;
    int c;
    for(int i=0; i<n; i++)
    {
        c=1;
        for(int j=0; j<m; j++)
        {
            if(b[j]!=a[i+j])
            {
                c=0;
                k = j-1;
                j = F[k];
                lap++;
            }
        }
        if(c==1)
        {
            printf("\nVi tri xuat hien mau P: %d", i);
        }
    }
    if(c==0)
    {
        printf("\nKhong tim thay mau P trong T");
    }
    return lap;
}
int main()
{
    char a[50], b[50];
    int n, m;
    n = nhap(a);
    fflush(stdin);
    m = nhap(b);
    inMang(a, n);
    inMang(b, m);
    int d=vetCan(a, n, b, m);
    printf("\nSo phep tinh lap: %d",d);
    return 0;
}
