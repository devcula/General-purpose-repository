#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<int64_t> a;
vector<int64_t> primes;
void prime_generator()
{
    int last=a[0];
    for(int64_t i=0;i<a.size();i++)
        if(a[i]>last)
        last=a[i];
    if(primes.size()==0)
    {
        primes.push_back(2);
    for(int j=3;j<last/2;j+=2)
    {
        int counter=1;
        for(int k=3;k<=sqrt(j);k+=2)
        {
            if(j%k==0)
            {
                counter=0;
                break;
            }
        }
        if(counter)
            primes.push_back(j);
    }
    }
    else if(last/2>primes[primes.size()-1])
    {
        for(int64_t i=primes[primes.size()-1]+1;i<=last/2;i++)
        {
            int counter=1;
            for(int64_t j=3;j<sqrt(i);j+=2)
            {
                if(i%j==0)
            {
                counter=0;
                break;
            }
            }
            if(counter)
                primes.push_back(i);
        }
    }
}
int64_t LeastPrimeDivisor(int64_t num)
{
    if(num==1)
        return 1;
    else if(num%2==0)
        return 2;
    else
    for(int64_t i=1;i<primes.size();i++)
    {
        if(num%primes[i]==0)
        {
            return primes[i];
            break;
        }
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
            {
                int64_t temp;
                cin>>temp;
                a.push_back(temp);
            }
        prime_generator();
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
        a.clear();
    }
    return 0;
}
