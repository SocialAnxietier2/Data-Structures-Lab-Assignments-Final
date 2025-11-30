#include <iostream>
using namespace std;

struct bst
{
    int data;
    bst *left;
    bst *right;
};
typedef struct bst node;

node *root = NULL;
node *q;
int flag = 0;

void create();
void insert();
void searchinsert(node *p);
void preprint(node *p);
void inprint(node *p);
void postprint(node *p);
void search(node *p,int x);
void search_nonrec();
void maxelement(node *p);
void minelement(node *p);
void maxdepth();
void mindepth();
int height(node *p);
void detectbst();
int isbst(node *p, int minv, int maxv);
void successor();
void predecessor();
node* find_min(node *p);
node* find_max(node *p);
void delete_node();
node* delete_item(node *p, int x);

int main()
{
    int ch,ch1;

    do
    {
        cout<<"\nmenu:";
        cout<<"\n0 create node";
        cout<<"\n1 insert";
        cout<<"\n2 search (non recursive)";
        cout<<"\n3 search (recursive)";
        cout<<"\n4 traversals";
        cout<<"\n5 delete node";
        cout<<"\n7 max element";
        cout<<"\n8 min element";
        cout<<"\n9 max depth";
        cout<<"\n10 min depth";
        cout<<"\n11 detect bst";
        cout<<"\n12 successor";
        cout<<"\n13 predecessor";
        cout<<"\n6 exit\n";
        cout<<"enter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 0: create(); break;

            case 1: insert(); break;

            case 2: search_nonrec(); break;

            case 3:
            {
                int ele;
                cout<<"enter element to search: ";
                cin>>ele;
                search(root,ele);
                if(flag == 0)
                cout<<"element not found\n";
            }
            break;

            case 4:
            do
            {
                cout<<"\nenter 1 preorder 2 inorder 3 postorder 4 exit: ";
                cin>>ch1;

                if(ch1 == 1) preprint(root);
                if(ch1 == 2) inprint(root);
                if(ch1 == 3) postprint(root);

                if(ch1==1||ch1==2||ch1==3) cout<<"\n";

            }while(ch1!=4);
            break;

            case 5: delete_node(); break;

            case 7: maxelement(root); cout<<"\n"; break;
            case 8: minelement(root); cout<<"\n"; break;

            case 9: maxdepth(); break;
            case 10: mindepth(); break;

            case 11: detectbst(); break;

            case 12: successor(); break;
            case 13: predecessor(); break;
        }

    }while(ch!=6);
}

void create()
{
    q = new node;
    q->left = NULL;
    cout<<"enter value to create node: ";
    cin>>q->data;
    q->right = NULL;
}

void insert()
{
    create();
    if(root == NULL)
        root = q;
    else
        searchinsert(root);
    cout<<"inserted\n";
}

void searchinsert(node *p)
{
    if(q->data < p->data && p->left == NULL)
        p->left = q;
    else if(q->data < p->data)
        searchinsert(p->left);
    else if(q->data > p->data && p->right == NULL)
        p->right = q;
    else if(q->data > p->data)
        searchinsert(p->right);
}

void preprint(node *p)
{
    if(p==NULL) return;
    cout<<p->data<<" ";
    preprint(p->left);
    preprint(p->right);
}

void inprint(node *p)
{
    if(p==NULL) return;
    inprint(p->left);
    cout<<p->data<<" ";
    inprint(p->right);
}

void postprint(node *p)
{
    if(p==NULL) return;
    postprint(p->left);
    postprint(p->right);
    cout<<p->data<<" ";
}

void search(node *p,int x)
{
    flag = 0;
    if(p==NULL) return;

    if(x == p->data)
    {
        cout<<"element found\n";
        flag = 1;
        return;
    }

    if(x < p->data)
        search(p->left,x);
    else
        search(p->right,x);
}

void search_nonrec()
{
    if(root == NULL)
    {
        cout<<"tree empty\n";
        return;
    }

    int x;
    cout<<"enter element to search: ";
    cin>>x;

    node *p = root;

    while(p != NULL)
    {
        if(x == p->data)
        {
            cout<<"element found\n";
            return;
        }
        if(x < p->data)
            p = p->left;
        else
            p = p->right;
    }

    cout<<"element not found\n";
}

void maxelement(node *p)
{
    while(p->right != NULL)
        p = p->right;
    cout<<"max = "<<p->data;
}

void minelement(node *p)
{
    while(p->left != NULL)
        p = p->left;
    cout<<"min = "<<p->data;
}

node* find_min(node *p)
{
    while(p->left != NULL)
        p = p->left;
    return p;
}

node* find_max(node *p)
{
    while(p->right != NULL)
        p = p->right;
    return p;
}

void delete_node()
{
    int x;
    cout<<"enter value to delete: ";
    cin>>x;
    root = delete_item(root,x);
    cout<<"deleted if existed\n";
}

node* delete_item(node *p, int x)
{
    if(p==NULL) return p;

    if(x < p->data)
        p->left = delete_item(p->left,x);

    else if(x > p->data)
        p->right = delete_item(p->right,x);

    else
    {
        if(p->left == NULL)
            return p->right;
        else if(p->right == NULL)
            return p->left;

        node *t = find_min(p->right);
        p->data = t->data;
        p->right = delete_item(p->right,t->data);
    }

    return p;
}

int height(node *p)
{
    if(p==NULL) return 0;
    int l = height(p->left);
    int r = height(p->right);
    return (l>r ? l : r) + 1;
}

void maxdepth()
{
    cout<<"max depth = "<<height(root)<<endl;
}

void mindepth()
{
    if(root==NULL)
    {
        cout<<"min depth = 0\n";
        return;
    }

    int l = height(root->left);
    int r = height(root->right);
    cout<<"min depth = "<<( (l<r ? l+1 : r+1) )<<endl;
}

int isbst(node *p, int minv, int maxv)
{
    if(p==NULL) return 1;
    if(p->data < minv || p->data > maxv) return 0;
    return isbst(p->left,minv,p->data-1) &&
           isbst(p->right,p->data+1,maxv);
}

void detectbst()
{
    if(isbst(root,-99,99))
         cout<<"tree is bst\n";
    else
         cout<<"not bst\n";
}

void successor()
{
    int x;
    cout<<"enter element: ";
    cin>>x;

    node *p = root;
    node *succ = NULL;

    while(p != NULL)
    {
        if(x < p->data)
        {
            succ = p;
            p = p->left;
        }
        else if(x > p->data)
            p = p->right;
        else
        {
            if(p->right != NULL)
                succ = find_min(p->right);
            break;
        }
    }

    if(succ == NULL)
        cout<<"no successor\n";
    else
        cout<<"successor = "<<succ->data<<endl;
}

void predecessor()
{
    int x;
    cout<<"enter element: ";
    cin>>x;

    node *p = root;
    node *pred = NULL;

    while(p != NULL)
    {
        if(x < p->data)
            p = p->left;

        else if(x > p->data)
        {
            pred = p;
            p = p->right;
        }

        else
        {
            if(p->left != NULL)
                pred = find_max(p->left);
            break;
        }
    }

    if(pred == NULL)
        cout<<"no predecessor\n";
    else
        cout<<"predecessor = "<<pred->data<<endl;
}