// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

static const int UNDEFINED = -1;

int GetNodeWithLeastDistance(vector<int>& Q, const vector<int>& dist)
{
    int minDistance = numeric_limits<int>::max();
    int minIndex = UNDEFINED;
    
    for (int i = 0; i < Q.size(); i++)
    {
        int node = Q[i];
        
        if (dist[node] < minDistance)
        {
            minDistance = dist[node];
            minIndex = i;
        }
    }
    
    int nodeWithLeastDistance = Q[minIndex];
    
    Q.erase(Q.begin() + minIndex);
    
    return nodeWithLeastDistance;
}

void Flip(vector<int>& path)
{
    int start = 0;
    int end = path.size() - 1;

    while (start < end)
    {
        int tmp = path[start];
        path[start] = path[end];
        path[end] = tmp;

        start++;
        end--;
    }
}

vector<int> MakePath(const vector<int>& prev, int start, int goal)
{
    vector<int> path;
    
    path.push_back(goal);
    
    for (int node = prev[goal]; node != start; node = prev[node])
    {
        path.push_back(node);
    }

    Flip(path);

    return path;
}

vector<int> FindLowestCostPath(const vector<vector<int>>& graph, int start, int goal)
{
    vector<int> dist(graph.size());
    vector<int> prev(graph.size());
    vector<int> Q(graph.size());
    
    for (int node = 0; node < graph.size(); node++)
    {
        dist[node] = numeric_limits<int>::max();
        prev[node] = UNDEFINED;
        Q[node] = node;
    }
    
    dist[start] = 0;
    
    while (!Q.empty())
    {
        int u = GetNodeWithLeastDistance(Q, dist);

        cout << "current: " << u << endl;
        
        if (u == goal)
        {
            break;
        }

        const vector<int>& neighbors = graph[u];
        
        for (const int v : neighbors)
        {
            int moveCost = (v-u) * (v-u);
            int alt = dist[u] + moveCost;
            if (alt < dist[v])
            {
                dist[v] = alt;
                prev[v] = u;
            }
        }
    }
    
    cout << "Min cost: " << dist[goal] << endl;
    
    return MakePath(prev, start, goal);
}

vector<int> FindLowestCostPath(const vector<vector<int>>& graph)
{
    return FindLowestCostPath(graph, 0, graph.size() - 1);
}

void TestDijkstra()
{
    vector<vector<int>> g = {{1,2,3},
                             {4,5,6},
                             {7,8},
                             {9},
                             {6},
                             {8,7},
                             {9,4},
                             {4,6},
                             {1,},
                             {1,4}
                            };

    vector<int> path = FindLowestCostPath(g);
    
    for (int node : path)
    {
        cout << node << ' ';
    }

    cout << endl;
}
