#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
bool isPrime(unsigned long long n,unsigned long long x)
{
    bool a[n];
    unsigned long long i,j;
    for(i=2; i<=n; i++)
    {
        a[i]=true;
    }
    for(i=2; i<=n; i++)
    {
        for(j=2*i; j<=n; j+=i)
        {
            a[j]=false;
        }
    }
    for(i=2; i<=n; i++)
    {
        if(x==i)
            return a[i];
    }
}
int main()
{
    unsigned long long n;
    printf("\nNhap n = ");
    scanf("%u", &n);
    int cs[n],sm[n];
    int count;
    unsigned long long i,j=0;
    printf("n=%d -> ",n);
    for( i = 2; i <= n; i++)
    {
        count = 0;
        while(1)
        {
            if(n % i == 0 && isPrime(n,i)==true)
            {
                n /= i;
                count++;
            }
            else if(n%i!=0)
            {
                break;
            }
        }
        if(count>0)
        {
            cs[j]=i;
            sm[j]=count;
            j++;
        }
    }
    printf("coso=[");
    for( i = 0; i <j; i++)
    {
        if(i==j-1)
        {
            printf("%d]",cs[i]);
            break;
        }
        printf("%d, ",cs[i]);

    }
    printf(",somu=[");
    for( i = 0; i <j; i++)
    {
        if(i==j-1)
        {
            printf("%d]",sm[i]);
            break;
        }
        printf("%d, ",sm[i]);
    }
}
