#include "bits/stdc++.h"
using namespace std;

class GraphColoring
{
    int numOfNode;
    vector<int> color;
    int s;
  public:
    GraphColoring(int n)
    {
        numOfNode = n;
        for (int i = 0; i < n; i++)
        {
            color.push_back(-1);
        }
        s = 0;
    }

    int printSolution()
    {
        return s;
    }

    bool isSafe(vector<vector<int> > graph, int node, int col)
    {
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (color[graph[node][i]] == col)
                return false;
        }
        return true;
    }

    void colorGraph(vector<vector<int> > graph, int node)
    {
        if (node >= numOfNode)
        {
            ++s;
            return;
        }
        for (int i = 0; i < 2; i++)
        {
            if (isSafe(graph, node, i))
            {
                color[node] = i;
                colorGraph(graph, node + 1);
                color[node] = -1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v, n, e;
    vector<vector<int> > graph;
    while (cin >> n)
    {
        if (!n)
            break;
        cin >> e;
        graph.resize(n);
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        GraphColoring gc(n);
        gc.colorGraph(graph, 0);
        if (gc.printSolution())
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
        graph.clear();
    }

    return 0;
}
