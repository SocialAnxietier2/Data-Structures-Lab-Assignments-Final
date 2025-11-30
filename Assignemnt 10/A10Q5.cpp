#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;
node *last = NULL;
node *arr[100];
int n;

void create()
{
    cout<<"enter how many nodes (max 100) ";
    cin>>n;
    cout<<"enter "<<n<<" numbers ";

    for(int i=0;i<n;i++)
    {
        node *t = new node;
        cin>>t->data;
        t->next = NULL;

        if(head==NULL)
        {
            head = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }

        arr[i] = t;
    }

    int make;
    cout<<"enter 1 to create a loop or 0 ";
    cin>>make;

    if(make==1)
    {
        int pos;
        cout<<"enter position to link last node to (0 to "<<n-1<<") ";
        cin>>pos;
        last->next = arr[pos];
    }
}

void hasloop()
{
    node *slow = head;
    node *fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
        {
            cout<<"true";
            return;
        }
    }

    cout<<"false";
}

int main()
{
    create();
    hasloop();
}