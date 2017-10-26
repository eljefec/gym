#include <iostream>
#include <vector>

using namespace std;

int GetCost(int node1, int node2)
{
    int diff = (node2 - node1);

    return diff * diff;
}

class Path
{
public:
    Path(int node)
        : cost(0)
    {
        path.push_back(node);
    }

    int Back() const
    {
        return path.back();
    }

    bool Meets(const Path& other) const
    {
        if (path.empty() || other.path.empty())
        {
            return false;
        }

        return (path.back() == other.path.back());
    }

    bool Reaches(int node) const
    {
        if (path.empty())
        {
            return false;
        }

        return (path.back() == node);
    }

    Path MakePathWithAppendedNode(int node) const
    {
        vector<int> newPath(path);
        newPath.push_back(node);

        return Path{cost + GetCost(node, path.back()), newPath};
    }

private:
    friend ostream& operator<<(ostream& os, const Path& p);

    Path(int cost, const std::vector<int>& path)
        : cost(cost),
          path(path)
    {
    }

    int cost;
    // Empty if no path exists.
    vector<int> path;
};

ostream& operator<<(ostream& os, const Path& p)
{
    os << "Cost: " << p.cost << ", Path: [";

    for (int node : p.path)
    {
        os << node << ' ';
    }

    os << ']' << endl;

    return os;
}

class Graph
{
public:
    Graph(const vector<vector<int>>& graph)
        : next_nodes(graph)
    {
        prev_nodes.resize(graph.size());

        for (int prevNode = 0; prevNode < graph.size(); prevNode++)
        {
            for (int nextNode : graph[prevNode])
            {
                prev_nodes[nextNode].push_back(prevNode);
            }
        }
    }

    const vector<int>& GetNext(int node)
    {
        return next_nodes[node];
    }

    const vector<int>& GetPrev(int node)
    {
        return prev_nodes[node];
    }

private:
    void CheckNode(int node) const
    {
        if (node < 0 || node >= next_nodes.size())
        {
            throw std::runtime_error("Invalid node value.");
        }
    }

    vector<vector<int>> next_nodes;
    vector<vector<int>> prev_nodes;
};

Path FindPath(const vector<vector<int>>& graph, int start, int goal)
{
    Graph g(graph);

    vector<Path> paths;
    paths.emplace_back(Path(start));

    while (true)
    {
        for (const Path& p : paths)
        {
            if (p.Reaches(goal))
            {
                return p;
            }
        }

        vector<Path> frontier = paths;
        paths.clear();

        for (const Path& p : frontier)
        {
            const vector<int>& nextNodes = g.GetNext(p.Back());

            for (int next : nextNodes)
            {
                paths.emplace_back(p.MakePathWithAppendedNode(next));
            }
        }

        cout << "paths.size(): " << paths.size() << endl;
    }
}

Path FindPath(const vector<vector<int>>& graph)
{
    return FindPath(graph, 0, graph.size() - 1);
}

void TestBFS()
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
    Path p = FindPath(g);
    cout << p << endl;
}
