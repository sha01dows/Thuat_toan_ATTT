#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    //w: he co so; p: truong huu han; a: so can bieu dien;
    int w;
    long long p;
    long long a;
    printf("Nhap vao he co so, truong huu han va so can bieu dien: \n");
    scanf("%d %I64d %I64d", &w, &p, &a);
    long long b[w];
    long long k;
    long long m=ceil(log(p)/log(2)+1);
    //m : do dai bit cua p
    long long t=(m/w);//t: do dai từ cua p
    printf("%I64d %I64d\n",m, t);
    for(long long i =1; i<=t; i++)
    {
        k=a/(pow(2,(t-i)*w));
        if(k==0){
            b[i]=0;
            printf("%I64d\t", b[i]);
            continue;
        }
        else{
            b[i]=k;
            printf("%I64d\t", b[i]);
            a=a-k*(pow(2,(t-i)*w));
        }

    }
}
