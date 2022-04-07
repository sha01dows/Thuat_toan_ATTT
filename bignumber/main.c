#include <stdio.h>
#include <stdlib.h>
#define max 50000

int arr_num(char num[])
{
    int i=0;
    char c;
    while(1)
    {
        scanf("%c",&c);
        if( c==' '|| c=='\n') break;
        num[i]=c;
        i++;
    }
    return i;
}

void ep_kieu(int a[], char b[], int n)
{
    for(int i=0; i<n; i++)
    {
        a[i]=(int)b[i]-48;
    }
}

void print_arr(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d", a[i]);
    }
}



void chen(int a[], int b[], int n, int len)
{
    for(int i=0; i<len-n; i++)
    {
        b[i]=0;
    }
    for(int i=len-n; i<len; i++)
    {
        b[i]=a[i-len+n];
    }
}

void add (int a[],int na, int b[],int nb, int c[])
{
    int lenght = na > nb ? na : nb;
    int a1[lenght], b1[lenght];
    chen(a, a1, na, lenght);
    chen(b, b1, nb, lenght);
    int extra=0;
    int temp;
    for(int i=lenght-1; i>=0; i--)
    {
        temp =a1[i]+b1[i]+extra;
        if(temp>=10)
        {
            c[i]=temp%10;
            extra=temp/10;
        }
        else
        {
            c[i]=temp;
            extra=0;
        }
    }
    printf("\n");
    for(int i=0; i<lenght; i++)
    {
        printf("%d", c[i]);
    }
}

void sub (int a[],int la, int b[],int lb, int c[])
{
    int length=la>=lb?la:lb;
    int a1[length], b1[length];
    chen(a, a1, la, length);
    chen(b, b1, lb, length);
    int extra=0;
    int temp;
    for(int i=length-1; i>=0; i--)
    {
        temp =la>lb?a1[i]-b1[i]-extra:b1[i]-a1[i]-extra;
        if(temp<0)
        {
            c[i]=temp+10;
            extra=1;
        }
        else
        {
            c[i]=temp;
            extra=0;
        }
    }
    printf("\n");
    for(int i=0; i<length; i++)
    {
        printf("%d", c[i]);
    }
}

void mul (int a[],int na, int b[],int nb, int c[])
{
    int *res;
    res=(int *)malloc(na+nb);
    int len=na+nb;
    for(int i=0; i<=len; i++)
    {
        res[i]=0;
        c[i]=0;
    }
    for(int m=na-1; m>=0; m--)
    {
        for(int n=nb-1; n>=0; n--)
        {
            res[m+n+1] += a [m] * b[n];
        }
    }
    for(int i=len-1; i>=0; i--)
    {
        if(res[i]>9)
        {
            res[i-1] +=res[i]/10;
            res[i]%=10;
        }
    }
    printf("\n");
    for(int i=0; i<len; i++)
    {
        c[i]+= res[i];
        printf("%d", c[i]);
    }
}

void chia(int a[],int b[],int la,int lb,int c[])
{
    int length=la>=lb?la:lb;
    int a1[length],a2[length],c1[length],d[length];
    int i,j,la1,t=0,k,z;
    int count=0;
    la1=lb;
    j=0;
    for(i=0; i<lb; i++)
    {
        a1[j]=a[i];
        j++;
    }
    chen(a1,c1,la1,length);
    chen(b,d,lb,length);
    count=0;
    if(soSanh(c1,d,length,length)==1)
    {
        while(1)
        {
            tru(c1,length,b,lb,a2);
            count++;
            for(k=0; k<length; k++)
            {
                c1[k]=a2[k];
            }
            if(soSanh(c1,d,length,length)==-1)
            {
                c[t]=count;
                t++;
                break;
            }
        }
        for(i=lb; i<length; i++)
        {
            count=0;
            for(z=length-1; z>0; z--)
            {
                if(z==length-1)
                {
                    c1[z]=a[i];
                }
                else
                {
                    c1[z]=a2[z+1];
                }
            }
            if(soSanh(c1,d,length,length)==-1)
            {
                c[t]=count;
                t++;
                for(k=0; k<length; k++)
                {
                    a2[k]=c1[k];
                }
            }
            if(soSanh(c1,d,length,length)==1)
            {
                while(1)
                {
                    tru(c1,length,b,lb,a2);
                    count++;
                    for(k=0; k<length; k++)
                    {
                        c1[k]=a2[k];
                    }
                    if(soSanh(c1,d,length,length)==-1)
                    {
                        c[t]=count;
                        t++;
                        break;
                    }
                }
            }
        }
    }
    else  if(soSanh(c1,d,length,length)==-1)
    {
        j=0;
        for(i=0; i<=lb; i++)
        {
            a1[j]=a[i];
            j++;
        }
        chuyenMang(a1,c1,lb+1,length);
        chuyenMang(b,d,lb,length);
        count=0;
        if(soSanh(c1,d,length,length)==1)
        {
            while(1)
            {
                tru(c1,length,b,lb,a2);
                count++;
                for(k=0; k<length; k++)
                {
                    c1[k]=a2[k];
                }
                if(soSanh(c1,d,length,length)==-1)
                {
                    c[t]=count;
                    t++;
                    break;
                }
            }
        }
        for(i=lb+1; i<length; i++)
        {
            count=0;
            for(z=length-1; z>0; z--)
            {
                if(z==length-1)
                {
                    c1[z]=a[i];
                }
                else
                {
                    c1[z]=a2[z+1];
                }
            }
            if(soSanh(c1,d,length,length)==-1)
            {
                c[t]=count;
                t++;
                for(k=0; k<length; k++)
                {
                    a2[k]=c1[k];
                }
            }
            if(soSanh(c1,d,length,length)==1)
            {
                while(1)
                {
                    tru(c1,length,b,lb,a2);
                    count++;
                    for(k=0; k<length; k++)
                    {
                        c1[k]=a2[k];
                    }
                    if(soSanh(c1,d,length,length)==-1)
                    {
                        c[t]=count;
                        t++;
                        break;
                    }
                }
            }
        }
    }
    printf("\n");
    for(int i=0; i<t; i++)
    {
        printf("%d", c[i]);
    }
}
int chuyensothanhMang(int b[])
{
    a=pow(2,(t-i)*w);
    int k=0;
    for(int i=a; i>=0; i/=10){
        b[i]=a%10;
        k++;
    }
    return k;
}
void chuyenMang(int t, int w, long long a, int a[],int na, int c[])
{
    int k[50];
   int h= chuyensothanhMang(k);
    for(long int i =1; i<=t; i++)
    {
        chia(a, k, na, h);
        if(k==0)
        {
            k[i]=0;
            printf("%lld\t", k[i]);
            continue;
        }
        else
        {
            k[i]=k;
            printf("%lld\t", k[i]);
            a=a-k*(pow(2,(t-i)*w));
        }

    }
}
int main()
{
    char a[50],b[50];
    int c[50], a1[50], b1[50];
    printf("Nhap so :\n");
    int na=arr_num(a);
    printf("Nhap so :\n");
    int nb= arr_num(b);
    ep_kieu(a1, a, na);
    ep_kieu(b1, b, nb);
    add(a1, na, b1, nb, c);
    sub(a1, na, b1, nb, c);
    mul(a1, na, b1, nb, c);
    return 0;
}
