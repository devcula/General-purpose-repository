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

vector<int> v,temp;
int length;
bool result=false;

int main(void)
{
    cin>>length;
    for(int i=0;i<length;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
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
    for(int i=0;i<length-1;i++)
    {
        int temp2=v[i];
        v[i]=v[i+1];
        v[i+1]=temp2;
        if(temp==v)
        {
            cout<<"yes"<<endl;
            cout<<"swap "<<i+1<<" "<<i+2;
            result=true;
            break;
        }
        else
            {
                temp2=v[i];
                v[i]=v[i+1];
                v[i+1]=temp2;
            }
    }
    if(!result)
        reversecheck();
}

void reversecheck()
{
    for(int i=0;i<length;i++)
    {
        int indexone=i, indextwo=i;
        for(int j=i+1;j<length;j++)
        {
            if(v[j]>v[j-1])
                break;
            else
                indextwo=j;
        }
        if(indexone!=indextwo)
        {
            int first=indexone;
            int last=indextwo;
            while(first!=last&&(last-first)!=-1)
            {
                int temp2=v[first];
                v[first]=v[last];
                v[last]=temp2;
                first++;
                last--;
            }
            if(v==temp)
            {
                result=true;
                cout<<"Yes"<<endl;
                cout<<"Reverse "<<(indexone+1)<<" "<<(indextwo+1);
                break;
            }
            else{
                cout<<"No";
                break;
            }
        }
    }
}
