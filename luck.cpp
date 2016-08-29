/*
*****File: luck.cpp
*****Author: Abhishek Prasad @ dEvCuLa
*****Date of completion: 29th August, 2016
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int64_t n,k,max_luck=0;
    cin>>n>>k;
    int64_t l[n],t[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>t[i];
        max_luck+=l[i];
    }
    int imp_count=0;
    for(int j=0;j<n;j++)
        if(t[j]==1)
        imp_count++;
    int shecanwin=imp_count-k;
    if(shecanwin<=0)
    {
        cout<<max_luck;
    }
    else
    {
        vector<int> imp;
        for(int k=0;k<n;k++)
            if(t[k]==1)
            imp.push_back(l[k]);
        sort(imp.begin(),imp.end());
        int negative_luck=0;
        for(int l=0;l<shecanwin;l++)
            negative_luck+=imp[l];
        max_luck-=2*negative_luck;
        cout<<max_luck;
   }
    return 0;
}
