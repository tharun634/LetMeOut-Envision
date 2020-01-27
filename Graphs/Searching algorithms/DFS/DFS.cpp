#include<iostream>
#include<vector>

using namespace std;

class Graph
{
public:
    int V; // number of vertices

    Graph(int v)
    {
        V=v;
    }
    void addEdge(vector<int> g[],int u,int v)
    {
        g[v].push_back(u); //If a is connected to b, then b is connected to a
        g[u].push_back(v);
    }
    void DFS(vector<int> g[],int v,bool visited[],int edgeTo[])
    {
        visited[v]=true;
         cout << v << " ";
        for(int i = 0; i<g[v].size();i++)
        {
            if(visited[i]==false)
            {
                visited[i]==true;
                DFS(g,i,visited,edgeTo);
                edgeTo[i]=v;
            }
        }
    }
    void DFSconf(vector<int> g[],int v)
    {
        bool visited[V]; // visited keeps track of which vertex is visited and which is not
        int edgeTo[V]; // edgeTo keeps track from which vertex we went to which
        for (int i = 0; i < V; i++)
        visited[i] = false; // setting every element of visited by default to FALSE
        DFS(g,v,visited,edgeTo);
    }
};
int main()
{
    Graph g(4);
    vector<int> x[4];
    g.addEdge(x,0, 1);
    g.addEdge(x,0, 2);
    g.addEdge(x,1, 2);
    g.addEdge(x,2, 0);
    g.addEdge(x,2, 3);
    g.addEdge(x,3, 3);
    cout << "DFS from vertex 0" << endl;
    g.DFSconf(x,0);

    return 0;
}
