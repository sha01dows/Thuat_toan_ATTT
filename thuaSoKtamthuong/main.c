#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(unsigned long long u,unsigned long long v)
{
    unsigned long long   q, d;
    long long r;
    if (v == 0)
    {
        d = u;
        return d;
    }
    else
    {
        while (1)
        {
            q = u / v;
            r = u - q*v;
            u = v;
            v = r;
            if (v == 0)
            {
                d = u;
                return d;
            }
        }
    }
}
void main()
{
    unsigned long long a,b,d,n;
    a=2;
    b=2;
    printf("nhap n:");
   scanf("%d",&n);
    while(1)
    {
        a=(a*a+1)%n;
        b=(b*b+1)%n;
        b=(b*b+1)%n;
        d=gcd(abs(a-b),n);
        printf("\n%ld %ld %ld\n",a,b,d);
        if(d>1 && d<n)
        {
            printf("d=%ld",d); break;
        }
        else if(d==n)
        {
            printf("tbai.");
            break;
        }
    }
}

