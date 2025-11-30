#include <iostream>
using namespace std;

int n;
int a[100];

void getdata()
{
    cout<<"enter how many numbers you want to enter (max 100) ";
    cin>>n;

    cout<<"enter "<<n<<" numbers ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void firstnonrepeat()
{
    for(int i=0;i<n;i++)
    {
        int c = 0;
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j] && i!=j)
            {
                c = 1;
            }
        }
        if(c==0)
        {
            cout<<a[i];
            return;
        }
    }
    cout<<"no non repeating element";
}

int main()
{
    getdata();
    firstnonrepeat();
}