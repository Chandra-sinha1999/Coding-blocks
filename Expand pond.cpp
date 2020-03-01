#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int> > m;
public:
    graph()
    {

    }
    void addedge(int u,int v)
    {
        m[u].push_back(v);
    }
    int bfs(int src)
    {
        queue<int> q;
        map<int,bool> vis;
        q.push(src);
        vis[src]=true;
        int count=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            list<int> :: iterator i;
            for(i=m[node].begin();i!=m[node].end();i++)
            {
                list<int> :: iterator j;
                int temp=*i;
                j=find(m[temp].begin(),m[temp].end(),1);
                if(!vis[temp]&&j!=m[temp].end())
                 {
                  q.push(temp);
                  vis[temp]=true;
                  count++;
                 }
            }
        }
        return count;
    }
};
int main(void)
{
    int n,m;
    cin>>n>>m;
    Graph g;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int b[n][m];
    int k=2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            b[i][j]=k;
            k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i-1)>=0)
                g.addedge(b[i][j],b[i-1][j]);
            if((i+1)<n)
                g.addedge(b[i][j],b[i+1][j]);
            if((j-1)>=0)
                g.addedge(b[i][j],b[i][j-1]);
            if((j+1)<m)
                g.addedge(b[i][j],b[i][j+1]);
            if(a[i][j]==0)
                g.addedge(b[i][j],0);
            if(a[i][j]==1)
                g.addedge(b[i][j],1);
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    int exp=g.bfs(b[i][j]);
                    if(exp>max)
                        max=exp;
                }
                else
                    continue;
            }
        }
        cout<<max;
}
