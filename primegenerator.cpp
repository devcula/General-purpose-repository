    #include <iostream>
    #include<math.h>
    using namespace std;

    int main() {

        int cases;
        cin>>cases;
        while(cases--)
        {
            int64_t m,n;
            cin>>m>>n;
            for(int64_t i=m;i<=n;i++)
            {
                if(i==2)
                    cout<<i<<endl;
                else if(i==3)
                    cout<<i<<endl;
                else if(i==5)
                    cout<<i<<endl;
                else
                {
                    if(i!=1)
                if(i!=2&&i%2!=0)
                if(i!=3&&i%3!=0)
                if(i!=5&&i%5!=0)
                {
                int count=1;
                for(int64_t j=2;j<=sqrt(i);j++)
                {
                    if(i%j==0)
                    {
                        count=0;
                        break;
                    }
                }
                if(count)
                cout<<i<<endl;
                }
                }
            }
        }
        return 0;
    }
