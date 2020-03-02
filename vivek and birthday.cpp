#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int> > m;
public:
    void addedge(int u,int v)
    {
        m[u].push_back(v);
        m[v].push_back(u);
    }
    void dfshelper(int node,map<int,bool> &vis,int &count)
    {
        vis[node]=true;
        count++;
        list<int> :: iterator i;
        for(i=m[node].begin();i!=m[node].end();i++)
        {
            if(vis[*i]==false)
                dfshelper(*i,vis,count);
        }
    }
    void dfs(int v)
    {
        map<int,bool> vis;
        int count=0;
        int max=INT_MAX;
        //map<int,list<int> > :: iterator j;
        for(int j=1;j<=v;j++)
        {
            if(vis[j]==false)
            {
                count=0;
                dfshelper(j,vis,count);
                if(count<max)
                    max=count;
            }
        }
        cout<<max<<endl;
    }
};
int main(void)
{
    int m,n;
    cin>>m>>n;
    Graph g;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.dfs(m);
}
