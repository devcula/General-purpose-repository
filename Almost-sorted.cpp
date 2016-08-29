/*
*****File: AlmostSorted.cpp
*****Author: Abhishek Prasad @ dEvCuLa
*****Date of completion: 8th August, 2016
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void swapcheck();
void reversecheck();

vector<int64_t> v,temp;
int64_t length;
bool result=false;

int main(void)
{
    cin>>length;
    for(int64_t i=0;i<length;i++)
    {
        int64_t temp2;
        cin>>temp2;
        v.push_back(temp2);
    }
    temp=v;
    sort(temp.begin(),temp.begin()+length);
    if(temp==v)
    {
        result=true;
        cout<<"yes"<<endl;
    }
    else
        swapcheck();
    return 0;
}

void swapcheck()
{
    int64_t err_count=0,first,last;
    for(int64_t i=0;i<length;i++)
    {
        if(v[i]!=temp[i])
            err_count++;
    }
    if(err_count<3)
    {
        for(int64_t j=0;j<length;j++)
        {
            if(v[j]!=temp[j])
            {
                first=j;
                break;
            }
        }
        for(int64_t k=0;k<length;k++)
        {
            if(v[k]!=temp[k]&&k!=first)
            {
                last=k;
                break;
            }
        }
        int64_t temp1=v[first];
        v[first]=v[last];
        v[last]=temp1;
        if(temp==v)
        {
            result=true;
            cout<<"yes"<<endl;
            cout<<"swap "<<first+1<<" "<<last+1;
        }
        else result=false;
    }
    else result=false;
    if(!result)
        reversecheck();
}

void reversecheck()
{
    for(int64_t i=0;i<length;i++)
    {
        int64_t indexone=i, indextwo=i;
        for(int64_t j=i+1;j<length;j++)
        {
            if(v[j]>v[j-1])
                break;
            else
                indextwo=j;
        }
        if(indexone!=indextwo)
        {
            int64_t first=indexone;
            int64_t last=indextwo;
            while(first!=last&&(last-first)!=-1)
            {
                int64_t temp2=v[first];
                v[first]=v[last];
                v[last]=temp2;
                first++;
                last--;
            }
            if(v==temp)
            {
                result=true;
                cout<<"yes"<<endl;
                cout<<"reverse "<<(indexone+1)<<" "<<(indextwo+1);
                break;
            }
            else{
                cout<<"no";
                break;
            }
        }
    }
}
