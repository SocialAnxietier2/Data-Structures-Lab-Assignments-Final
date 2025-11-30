#include <iostream>
using namespace std;

int n;
int a[100];
int dup = 0;

void getdata()
{
    cout<<"enter how many numbers you want to enter ";
    cin>>n;
    cout<<"enter "<<n<<" numbers ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void checkdup()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                dup = 1;
            }
        }
    }
}

int main()
{
    getdata();
    checkdup();
    if(dup==1)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}