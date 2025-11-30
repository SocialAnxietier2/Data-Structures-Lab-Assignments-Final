#include <iostream>
using namespace std;

int h[200];
int n = 0;

void insert_value()
{
    int x;
    cout<<"enter value to insert: ";
    cin>>x;

    n++;
    h[n] = x;

    int i = n;
    while(i > 1 && h[i] > h[i/2])
    {
        int t = h[i];
        h[i] = h[i/2];
        h[i/2] = t;
        i = i/2;
    }

    cout<<"inserted\n";
}

void delete_max()
{
    if(n == 0)
    {
        cout<<"queue empty\n";
        return;
    }

    cout<<"deleted max = "<<h[1]<<endl;

    h[1] = h[n];
    n--;

    int i = 1;
    while(true)
    {
        int l = 2*i;
        int r = 2*i+1;
        int big = i;

        if(l <= n && h[l] > h[big]) big = l;
        if(r <= n && h[r] > h[big]) big = r;

        if(big == i) break;

        int t = h[i];
        h[i] = h[big];
        h[big] = t;

        i = big;
    }
}

void display()
{
    if(n == 0)
    {
        cout<<"queue empty\n";
        return;
    }

    cout<<"priority queue: ";
    for(int i=1;i<=n;i++)
        cout<<h[i]<<" ";
    cout<<endl;
}

int main()
{
    int ch;

    while(true)
    {
        cout<<"\nmenu:";
        cout<<"\n1 insert value";
        cout<<"\n2 delete max";
        cout<<"\n3 display queue";
        cout<<"\n4 exit";
        cout<<"\nenter choice: ";
        cin>>ch;

        if(ch == 1) insert_value();
        else if(ch == 2) delete_max();
        else if(ch == 3) display();
        else return 0;
    }
}