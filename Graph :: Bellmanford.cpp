#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src,des,weight;
};
class Graph
{
public:
    int v,e;
    Edge* edge;
    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        edge=new Edge[e];
    }
    void addedge(int u,int v,int w,int count)
    {
        edge[count].src=u;
        edge[count].des=v;
        edge[count].weight=w;
    }
    void Bellmanford(int src)
    {
        int distance[v];
        for(int i=0;i<v;i++)
        {
            if(i==src)
                distance[i]=0;
            else
                distance[i]=INT_MAX;
        }
        for(int i=1;i<v;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src=edge[j].src;
                int des=edge[j].des;
                int wt=edge[j].weight;
                //ralaxation code
                if(distance[src]!=INT_MAX&& distance[src]+wt< distance[des])
                {
                    distance[des]=distance[src]+wt;
                }
            }
        }
        //for negative weight cycles
        for(int j=0;j<e;j++)
            {
                int src=edge[j].src;
                int des=edge[j].des;
                int wt=edge[j].weight;
                //ralaxation code
                if(distance[src]!=INT_MAX&& distance[src]+wt< distance[des])
                {
                    cout<<" Negative cycle detected ";
                }
            }
        for(int i=0;i<v;i++)
        {
            cout<<i<<" - "<<distance[i]<<endl;
        }
    }
};
int main(void)
{
    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addedge(u,v,w,i);
    }
    g.Bellmanford(0);
}
