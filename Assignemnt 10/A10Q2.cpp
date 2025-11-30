#include <iostream>
using namespace std;

int n1,n2;
int a[100],b[100];

void getdata()
{
    cout<<"enter how many numbers in first array ";
    cin>>n1;
    cout<<"enter "<<n1<<" numbers ";
    for(int i=0;i<n1;i++)
    {
        cin>>a[i];
    }

    cout<<"enter how many numbers in second array ";
    cin>>n2;
    cout<<"enter "<<n2<<" numbers";
    for(int i=0;i<n2;i++)
    {
        cin>>b[i];
    }
}

void common()
{
    cout<<"common elements are ";
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(a[i]==b[j])
            {
                cout<<a[i]<<" ";
            }
        }
    }
}

int main()
{
    getdata();
    common();
}