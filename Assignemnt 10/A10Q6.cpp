#include <iostream>
using namespace std;

int n;
int a[100];

void getdata()
{
    cout<<"enter how many nodes in tree (max 100) ";
    cin>>n;

    cout<<"enter "<<n<<" node values ";
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
                cout<<"duplicates found";
                return;
            }
        }
    }

    cout<<"no duplicates";
}

int main()
{
    getdata();
    checkdup();
}