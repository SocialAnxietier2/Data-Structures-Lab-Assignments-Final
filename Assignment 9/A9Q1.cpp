#include <iostream>
using namespace std;

int n;
int g[100][100];
int vis[100];

void bfs()
{
    for(int i=0;i<n;i++) vis[i]=0;
    int q[100],f=0,r=0;
    int s;
    cout<<"enter start node:"<<endl;
    cin>>s;
    vis[s]=1;
    q[r++]=s;
    while(f<r)
    {
        int u=q[f++];
        cout<<u<<" ";
        for(int v=0;v<n;v++)
        {
            if(g[u][v]==1 && vis[v]==0)
            {
                vis[v]=1;
                q[r++]=v;
            }
        }
    }
    cout<<endl;
}

void dfs_run(int u)
{
    vis[u]=1;
    cout<<u<<" ";
    for(int v=0;v<n;v++)
    {
        if(g[u][v]==1 && vis[v]==0) dfs_run(v);
    }
}

void dfs()
{
    for(int i=0;i<n;i++) vis[i]=0;
    int s;
    cout<<"enter start node:"<<endl;
    cin>>s;
    dfs_run(s);
    cout<<endl;
}

int findp(int p[], int i)
{
    while(p[i]!=i) i=p[i];
    return i;
}

void kruskal()
{
    int p[100];
    for(int i=0;i<n;i++) p[i]=i;

    int e=0,total=0;

    while(e<n-1)
    {
        int mn=1000,a=-1,b=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]!=0 && g[i][j]<mn)
                {
                    mn=g[i][j];
                    a=i;
                    b=j;
                }
            }
        }

        g[a][b]=0;
        g[b][a]=0;

        int pa=findp(p,a);
        int pb=findp(p,b);

        if(pa!=pb)
        {
            p[pb]=pa;
            cout<<a<<" "<<b<<" "<<mn<<endl;
            total+=mn;
            e++;
        }
    }

    cout<<"total "<<total<<endl;
}

void prim()
{
    int key[100];
    int in[100];

    for(int i=0;i<n;i++)
    {
        key[i]=1000;
        in[i]=0;
    }

    key[0]=0;

    for(int c=0;c<n;c++)
    {
        int mn=1000,u=-1;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0 && key[i]<mn)
            {
                mn=key[i];
                u=i;
            }
        }

        in[u]=1;

        for(int v=0;v<n;v++)
        {
            if(g[u][v]!=0 && in[v]==0 && g[u][v]<key[v])
            {
                key[v]=g[u][v];
            }
        }
    }

    int total=0;
    for(int i=0;i<n;i++) total+=key[i];
    cout<<"total "<<total<<endl;
}

void dijkstra()
{
    int dist[100], used[100];
    for(int i=0;i<n;i++)
    {
        dist[i]=1000;
        used[i]=0;
    }

    int s;
    cout<<"enter start node:"<<endl;
    cin>>s;
    dist[s]=0;

    for(int c=0;c<n;c++)
    {
        int mn=1000,u=-1;
        for(int i=0;i<n;i++)
        {
            if(used[i]==0 && dist[i]<mn)
            {
                mn=dist[i];
                u=i;
            }
        }
        if(u==-1) break;
        used[u]=1;

        for(int v=0;v<n;v++)
        {
            if(g[u][v]!=0 && dist[u]+g[u][v] < dist[v])
            {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }

    for(int i=0;i<n;i++) cout<<i<<" "<<dist[i]<<endl;
}

int main()
{
    cout<<"enter n:"<<endl;
    cin>>n;

    cout<<"enter "<<n<<"x"<<n<<" matrix:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>g[i][j];
    }

    int ch=1;
    while(ch!=0)
    {
        cout<<"1 bfs"<<endl;
        cout<<"2 dfs"<<endl;
        cout<<"3 kruskal"<<endl;
        cout<<"4 prim"<<endl;
        cout<<"5 dijkstra"<<endl;
        cout<<"0 exit"<<endl;
        cin>>ch;

        if(ch==1) bfs();
        if(ch==2) dfs();
        if(ch==3) kruskal();
        if(ch==4) prim();
        if(ch==5) dijkstra();
    }

    return 0;
}