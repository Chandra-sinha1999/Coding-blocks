#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
    map<T,list<pair<T,int> > > m;
    public:
    void addedge(T u,T v,int w,bool bidir=true)
    {
        m[u].push_back(make_pair(v,w));
        if(bidir)
        {
            m[v].push_back(make_pair(u,w));
        }
    }
    void dijikastra(T src)
    {
        map<T,int> dist;
        for(auto i:m)
        {
            dist[i.first]=INT_MAX;
        }
        set<int,T> s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto ele=*(s.begin());
            T node=ele.second;
            int distance=ele.first;
            s.erase(s.begin());
            for(auto j:m[node])
            {
                if(j.second + distance < dist[j.first])
                {
                    //updation
                    T dest=j.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest]=j.second+distance;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }
        for(auto d:dist)
        cout<<d.first<<" and "<<d.second<<endl;
    }
};
int main(void)
{
    Graph<T> g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);
    g.dijikastra(1);
}
