#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    unordered_map<int,list<pair<int,int>>> m;
    Graph(int v)
    {
        V=v;
    }
    void addEdge(int u,int v,int dist)
    {
        m[u].push_back(make_pair(v,dist)); //If a is connected to b, then b is connected to a
        m[v].push_back(make_pair(u,dist));
    }
    void printAdj()
    {

        for(auto j:m)
        {
            cout<<j.first<<"->";
            for(auto l: j.second)
                cout<<"("<<l.first<<","<<l.second<<")";
            cout<<endl;
        }
    }
    void dijkstra(int s)
    {
        int source = s;
        bool visited[V+1];
        int mini,dist,t,te;
        list<pair<int,int>> curr;
        int distance[V+1];
        distance[s]=0;
        dist = 0;

        for(int i=0; i<=V; i++)
            distance[i]=0;


        for(int c = 1; c < V; c++) //starts from 1 since my graph input starts from 1
        {
            curr = m[s];
            mini = INT_MAX;
            if(!visited[s])
            {
                for(auto x:curr)
                {

                    if(x.second < mini&&!visited[x.first])
                    {
                        mini = x.second;
                        te = x.first;
                    }
                }

                dist+=mini;
                visited[s]=true;
                s = te;
                distance[s]=dist;

            }
        }
        for(int i = 1; i <= V; i++)
        {
            cout << " Distance of " << i << " from " << source << " " << distance[i] << endl;
        }

    }
};
int main()
{
    Graph g(4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printAdj();
    g.dijkstra(2);
    return 0;
}
