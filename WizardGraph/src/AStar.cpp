#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

namespace AStar
{
    int HeuristicCostEstimate(int start, int goal)
    {
        return abs(goal - start);
    }

    int Distance(int node, int other)
    {
        int diff = other - node;

        return diff * diff;
    }

    struct NodeCost
    {
        int node;
        int cost;

        bool operator<(const NodeCost& other) const
        {
            return cost < other.cost;
        }
    };

    int GetOpenNodeWithLowestF(const set<int>& open, const unordered_map<int, int>& f)
    {
        int nodeWithLowestF = -1;
        int lowestF = numeric_limits<int>::max();
        for (int node : open)
        {
            auto it = f.find(node);

            assert(it != f.end());

            const int nodeF = (*it).second;
            if (nodeF < lowestF)
            {
                nodeWithLowestF = node;
                lowestF = nodeF;
            }
        }

        return nodeWithLowestF;
    }

    vector<int> ReconstructPath(const unordered_map<int, int>& cameFrom, int current)
    {
        vector<int> path;
        path.push_back(current);

        auto it = cameFrom.find(current);

        while (it != cameFrom.end())
        {
            current = (*it).second;
            path.push_back(current);

            it = cameFrom.find(current);
        }

        return path;
    }

    void InitializeWithInfinity(unordered_map<int, int>& score, const vector<vector<int>>& graph)
    {
        for (int node = 0; node < graph.size(); node++)
        {
            score[node] = numeric_limits<int>::max();
        }
    }

    vector<int> FindLowestCostPath(const vector<vector<int>>& graph, int start, int goal)
    {
        set<int> closed;
        set<int> open;
        open.insert(start);

        unordered_map<int, int> cameFrom;

        unordered_map<int, int> g;
        InitializeWithInfinity(g, graph);
        g[start] = 0;

        unordered_map<int, int> f;
        InitializeWithInfinity(f, graph);

        f[start] = HeuristicCostEstimate(start, goal);

        while (!open.empty())
        {
            int current = GetOpenNodeWithLowestF(open, f);
            cout << "current: " << current << endl;

            if (current == goal)
            {
                cout << "min cost: " << g[goal] << endl;
                return ReconstructPath(cameFrom, current);
            }

            open.erase(current);
            closed.insert(current);

            const vector<int>& neighbors = graph[current];

            for (const int neighbor : neighbors)
            {
                if (closed.count(neighbor) > 0)
                {
                    continue;
                }

                if (open.count(neighbor) == 0)
                {
                    open.insert(neighbor);
                }

                int tentative_g = g[current] + Distance(current, neighbor);
                if (tentative_g >= g[neighbor])
                {
                    continue;
                }

                cameFrom[neighbor] = current;
                g[neighbor] = tentative_g;
                f[neighbor] = g[neighbor] + HeuristicCostEstimate(neighbor, goal);
            }
        }

        return {};
    }

    vector<int> FindLowestCostPath(const vector<vector<int>>& graph)
    {
        return FindLowestCostPath(graph, 0, graph.size() - 1);
    }
} // namespace AStar

void TestAStar()
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

    vector<int> path = AStar::FindLowestCostPath(g);
    
    for (int node : path)
    {
        cout << node << ' ';
    }

    cout << endl;
}
