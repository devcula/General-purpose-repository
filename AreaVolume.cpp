/*
*****File: AreaVolume.cpp
*****Author: Abhishek Prasad @ dEvCuLa
*****Date of creation and completion: 8th August, 2016
*/

#define PI 3.14159265358979323846264

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void calc_area();
void calc_volume();

vector<int> a,b;
double area=0;
double volume=0;
int n,start_limit,end_limit;

int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int j=0;j<n;j++)
    {
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    cin>>start_limit>>end_limit;
    calc_area();
    calc_volume();
    return 0;
}

void calc_area()
{
    for(double i=start_limit;i<=end_limit;i+=0.001)
    {
        double func_value=0;
        for(int j=0;j<n;j++)
        {
            func_value+=a[j]*pow(i,b[j]);
        }
        area+=(0.001)*func_value;
    }
    cout<<fixed<<area<<endl;
}

void calc_volume()
{
    for(double i=start_limit;i<=end_limit;i+=0.001)
    {
        double func_value=0,disk_area;
        for(int j=0;j<n;j++)
        {
            func_value+=a[j]*pow(i,b[j]);
        }
        disk_area=PI*pow(func_value,2);
        volume+=disk_area*(0.001);
    }
    cout<<fixed<<volume;
}
