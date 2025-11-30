#include <iostream>
using namespace std;

int a[200];
int n;

void heapify_max(int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int big = i;

    if(l<n && a[l] > a[big]) big = l;
    if(r<n && a[r] > a[big]) big = r;

    if(big != i)
    {
        int t = a[i];
        a[i] = a[big];
        a[big] = t;
        heapify_max(big);
    }
}

void heapify_min(int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int small = i;

    if(l<n && a[l] < a[small]) small = l;
    if(r<n && a[r] < a[small]) small = r;

    if(small != i)
    {
        int t = a[i];
        a[i] = a[small];
        a[small] = t;
        heapify_min(small);
    }
}

void heapsort_inc()
{
    for(int i=n/2-1;i>=0;i--)
        heapify_max(i);

    for(int i=n-1;i>=0;i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;

        n = i;
        heapify_max(0);
    }
}

void heapsort_dec()
{
    for(int i=n/2-1;i>=0;i--)
        heapify_min(i);

    for(int i=n-1;i>=0;i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;

        n = i;
        heapify_min(0);
    }
}

int main()
{
    cout<<"enter how many numbers you want to sort: ";
    cin>>n;

    cout<<"enter "<<n<<" numbers separated by space: ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    int ch;
    cout<<"enter 1 for increasing order or 2 for decreasing order: ";
    cin>>ch;

    int temp = n;

    if(ch == 1)
        heapsort_inc();
    else
        heapsort_dec();

    n = temp;

    cout<<"sorted result: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}