#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Edge
{
public:
    int v1 = 0;
    int v2 = 0;
    int weight = 0;

    Edge(int v1, int v2, int weight)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->weight = weight;
    }
};

vector<vector<Edge *>> graph;

int getIdx(int v1, int v2)
{
    for (int i = 0; i < graph[v1].size(); i++)
    {
        if (graph[v1][i]->v2 == v2)
            return i;
    }
    return -1;
}

//vertex.======================================

void addVertex(int v)
{
    if (graph.size() == v)
    {
        vector<Edge *> innerGraph;
        graph.push_back(innerGraph);
    }
}

void removeVertex(int v)
{
    for (Edge *e : graph[v])
    {
        int idx = getIdx(e->v2, v);
        graph[e->v2].erase(graph[e->v2].begin() + idx);
    }

    graph.erase(graph.begin() + v);
}

//addEdge.=============================================

bool containsEdge(int v1, int v2)
{
    if (v1 < graph.size() && v2 < graph.size() && getIdx(v1, v2) != -1)
        return true;
    return false;
}

int noOfEdge()
{
    int count = 0;
    for (vector<Edge *> a : graph)
    {
        count += a.size();
    }
    return count / 2;
}

void addEdge(int v1, int v2, int weight)
{
    if (v1 < graph.size() && v2 < graph.size())
    {
        graph[v1].push_back(new Edge(v1, v2, weight));
        graph[v2].push_back(new Edge(v2, v1, weight));
    }
}

void removeEdge(int v1, int v2)
{

    int i1 = getIdx(v1, v2);
    graph[v1].erase(graph[v1].begin() + i1);

    int i2 = getIdx(v2, v1);
    graph[v2].erase(graph[v2].begin() + i2);
}

// display.======================================================

void display()
{
    string sb = "";
    for (int i = 0; i < graph.size(); i++)
    {
        for (Edge *e : graph[i])
        {
            sb += "(" + to_string(e->v1) + "," + to_string(e->v2) + ")" + "@" + to_string(e->weight) + " ";
        }

        sb += "\n";
    }

    cout << sb << endl;
}

//hasPath.=====================================================

bool hasPath(int src, int desti, vector<bool> isVisited, string ans)
{
    if (src == desti)
    {
        cout << ans << " -> ";
        return true;
    }

    isVisited[src] = true;
    for (Edge *e : graph[src])
    {
        if (isVisited[e->v2])
            continue;

        bool res = hasPath(e->v2, desti, isVisited, ans + to_string(src) + " ");
        if (res)
        {
            return true;
        }
    }

    return false;
}

int printAllPath(int src, int desti, vector<int> isVisited, string ans, int wsf)
{
    if (src == desti)
    {
        cout << ans + to_string(src) + " @ " + to_string(wsf) << "\n";
        return 1;
    }

    int count = 0;
    isVisited[src] = true;
    for (Edge *e : graph[src])
    {
        if (isVisited[e->v2])
            continue;

        count += printAllPath(e->v2, desti, isVisited, ans + to_string(src) + " ", wsf + e->weight);
    }

    isVisited[src] = false;
    return count;
}

class minWeightPair
{
public:
    int wsf = 0;
    string psf = "";

    minWeightPair(int wsf, string psf)
    {
        this->wsf = wsf;
        this->psf = psf;
    }
};

minWeightPair *minimumWeightPath(int src, int desti, vector<int> isVisited)
{
    if (src == desti)
    {
        minWeightPair *p = new minWeightPair(0, to_string(src));
        return p;
    }

    isVisited[src] = true;
    minWeightPair *myAns = new minWeightPair(1000000, "");
    for (Edge *e : graph[src])
    {
        if (isVisited[e->v2])
            continue;

        minWeightPair *recAns = minimumWeightPath(e->v2, desti, isVisited);
        if (recAns->wsf + e->weight < myAns->wsf)
        {
            myAns->wsf = recAns->wsf + e->weight;
            myAns->psf = to_string(src) + recAns->psf;
        }
    }

    isVisited[src] = false;
    return myAns;
}

class minEdgePair
{
public:
    int wsf = 0;
    string psf = "";
    int noe = 0;

    minEdgePair(int wsf, string psf,int noe)
    {
        this->wsf = wsf;
        this->psf = psf;
        this->noe = noe;
    }
};

minEdgePair *minimumEdgePath(int src, int desti, vector<int> isVisited)
{
    if (src == desti)
    {
        minEdgePair *p = new minEdgePair(0, to_string(src),0);
        return p;
    }

    isVisited[src] = true;
    minEdgePair *myAns = new minEdgePair(1000000, "",0);
    for (Edge *e : graph[src])
    {
        if (isVisited[e->v2])
            continue;

        minEdgePair *recAns = minimumEdgePath(e->v2, desti, isVisited);
        if (recAns->noe < myAns->noe)
        {
            myAns->wsf = recAns->wsf + e->weight;
            myAns->psf = to_string(src) + recAns->psf;
            myAns->noe++;
        }
    }

    isVisited[src] = false;
    return myAns;
}

void hasPath()
{
    vector<int> isVisited(graph.size(), false);
    // removeEdge(3, 4);
    // cout<<(hasPath(0, 6, isVisited, ""));
    // cout << (printAllPath(0, 6, isVisited, "", 0));

   // minWeightPair *ans = minimumWeightPath(0, 6, isVisited);
    minEdgePair *ans=minimumEdgePath(0,6,isVisited);
    cout << ans->wsf << " " << ans->psf<< endl;
}

//==============================================================
void constructGraph()
{
    for (int i = 0; i < 7; i++)
    {
        addVertex(i);
    }

    addEdge(0, 1, 10);
    addEdge(0, 3, 40);
    addEdge(1, 2, 10);
    addEdge(2, 3, 10);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);

    //    removeVertex(3);
    display();
}

solve()
{
    constructGraph();
    hasPath();
}

int main(int args, char **argv)
{
    solve();
    return 1;
}

