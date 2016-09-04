#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define length 1000000
int a[length];

int64_t LeastPrimeDivisor(int64_t num)
{
    if(num%2==0)
        return 2;
    else
    {
        len=num/2+1;
        bool primes[len];
        for(int64_t i=1;i<len;i++)
            primes[i]=true;
        
    }
}

void update(int64_t l,int64_t r)
{
    for(int64_t i=l;i<=r;i++)
        a[i]/=LeastPrimeDivisor(a[i]);
}

int64_t maximum(int64_t num1,int64_t num2)
{
    if(num1>num2)
        return num1;
    else return num2;
}

void get(int64_t l,int64_t r)
{
    int64_t result=1;
    for(int64_t i=l;i<=r;i++)
        result=maximum(result,LeastPrimeDivisor(a[i]));
    cout<<result<<endl;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int64_t sizeofarray,queries;
        cin>>sizeofarray>>queries;
        for(int64_t i=0;i<sizeofarray;i++)
            cin>>a[i];
        for(int j=0;j<queries;j++)
        {
            int type;
            int64_t l,r;
            cin>>type;
            cin>>l>>r;
            if(type==0)
                update(l-1,r-1);
            else
                get(l-1,r-1);
        }
    }
    return 0;
}
