#include<iostream>
#include<vector>
#include<queue>
#include<list>
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
    void BFS(vector<int> g[],int s)
    {
        bool visited[V]; // visited keeps track of which vertex is visited and which is not
        for (int i = 0; i < V; i++)
        visited[i] = false; // setting every element of visited by default to FALSE

        queue<int> q;
        q.push(s);
        int x;
        visited[s]=true;
        while(!q.empty())
        {
            x = q.front();
            cout << x<< " ";
            q.pop();
            for(int i =0 ; i < g[x].size();i++)
                if(!visited[i])
                {visited[i] = true; q.push(i);}

        }
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
    cout << "BFS from vertex 0" << endl;
    g.BFS(x,2);

    return 0;
}
