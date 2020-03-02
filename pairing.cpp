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
    void dfshelper(int node,map<int,bool> &vis)
    {
        vis[node]=true;
        list<int> :: iterator i;
        for(i=m[node].begin();i!=m[node].end();i++)
        {
            if(vis[*i]==false)
                dfshelper(*i,vis);
        }
    }
    int dfs(int src)
    {
        map<int,bool> vis;
        dfshelper(src,vis);
        map<int,list<int> > :: iterator j;
        int count=0;
        for(j=m.begin();j!=m.end();j++)
        {
            if(vis[j->first]==true)
                count++;
        }
        return count;
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
    int res=g.dfs(0);
    res=res*(m-res);
    cout<<res<<endl;
}
