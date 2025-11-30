#include <iostream>
using namespace std;

int n;
int a[100];
int used[100];

void getdata()
{
    cout<<"enter how many numbers you want to enter (max 100) ";
    cin>>n;

    cout<<"enter "<<n<<" numbers ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        used[i] = 0;
    }
}

void freq()
{
    for(int i=0;i<n;i++)
    {
        if(used[i]==1)
        {
            continue;
        }

        int c = 1;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                c++;
                used[j] = 1;
            }
        }

        cout<<a[i]<<" appears "<<c<<" times"<<endl;
    }
}

int main()
{
    getdata();
    freq();
}