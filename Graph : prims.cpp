#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int v;
    list<pair<int,int> >*adj;
    Graph(int V)
    {
        v=V;
        adj=new list<pair<int,int> >[V];
    }
    void addedge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int findmin(int *weight,bool *vis,int v)
    {
        int min=INT_MAX;
        for(int i=0;i<v;i++)
        {
            if(weight[i]<min&&vis[i]==false)
                min=i;
        }
        return min;
    }
    void prims()
    {
        bool *vis=new bool[v];
        int *par=new int[v];
        int *weight=new int[v];
        for(int i=0;i<v;i++)
        {
            vis[i]=false;
            weight[i]=INT_MAX;
        }
        par[0]=-1;
        weight[0]=0;
        for(int i=0;i<v;i++)
        {
            int minvertex=findmin(weight,vis,v);
            vis[minvertex]=true;
            list<pair<int,int> > :: iterator j;
            for(j=adj[minvertex].begin();j!=adj[minvertex].end();j++)
            {
                if(!vis[j->first])
                {
                    if(weight[j->first]>j->second)
                    {
                        par[j->first]=minvertex;
                        weight[j->first]=j->second;
                    }
                }
            }
        }
        for(int i=1;i<v;i++)
        {
            cout<<i<<"--"<<par[i]<<" "<<weight[i]<<endl;
        }
    }
};
int main(void)
{
   int n,e;
   cin>>n>>e;
   Graph g(n);
   for(int i=0;i<e;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
       g.addedge(u,v,w);
   }
   g.prims();
}
