#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int check();
void swapcheck();
void doswap();
void reversecheck();

vector<int> v;
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
    if(check())
    {
        result=true;
        cout<<"yes"<<endl;
    }
    else
        swapcheck();
    return 0;
}

int check()
{
    vector<int> temp;
    temp=v;
    sort(temp.begin(),temp.begin()+length);
    if(v==temp)
        return 1;
    else
        return 0;
}

void doswap(int a,int b)
{
    int temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}

void swapcheck()
{
    for(int i=0;i<length-1;i++)
    {
        doswap(i,i+1);
        if(check())
        {
            cout<<"yes"<<endl;
            cout<<"swap "<<i+1<<" "<<i+2;
            result=true;
            break;
        }
        else
            doswap(i,i+1);
    }
    if(!result)
        reversecheck();
}

void reversecheck()
{

}
