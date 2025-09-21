#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

template<typename T>

THIS IS THE NON WEIGHTED GRAPH
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        if (direction == 1) {
            // Directed edge
            adjList[u].push_back(v);
        } else {
            // Undirected edge
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout << "Printing the Graph:" << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << ": { ";
            for (auto p : i.second) {
                cout << "{ " << p << ", "  << "} ";
            }
            cout << "}" << endl;
        }
    }
};






//THIS IS THE WEIGHTED GRAPH
class GraphWt {
public:
    unordered_map<T, list<pair<T, T>>> adjList;

    void addEdge(T u, T v, int wt, bool direction) {
        if (direction == 1) {
            // Directed edge
            adjList[u].push_back(make_pair(v, wt));
        } else {
            // Undirected edge
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }
        cout << "Printing the Graph:" << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << ": { ";
            for (auto p : i.second) {
                cout << "{ " << p.first << ", " << p.second << "} ";
            }
            cout << "}" << endl;
        }
    }

    void bfs(T src,  unordered_map<T, bool>& vis){
        queue<T> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();

            for(auto nbr: adjList[frontNode]){
                T nbrData = nbr.first;
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
        
    }

    void dfs(T src,  unordered_map<T, bool>& vis){
        vis[src] = true;
        cout<< src << " ";
        for(auto nbr: adjList[src]){
            T nbrData = nbr.first;
            if (!vis[nbrData])
            {
                dfs(nbrData, vis);
            }
            
        }

    }
};

int main() {
//    Graph<int> g;
//     g.addEdge(0, 1,  0);
//     g.addEdge(1, 2,  0);
//     g.addEdge(1, 3,  0);
//     g.addEdge(2, 3,  0);

    GraphWt<int> g;
    g.addEdge(0, 1, 10, 0);
    g.addEdge(1, 2, 20, 0);
    g.addEdge(1, 3, 40, 0);
    g.addEdge(2, 3, 50, 0);

    // unordered_map<int, bool> visited;
    // for (int i = 0; i <= 3; i++)
    // {
    //     if (!visited[i])
    //     {
    //        g.bfs(i, visited);
    //     }
        
    // }

    unordered_map<int, bool> visited;
    for (int i = 0; i <= 3; i++)
    {
        if (!visited[i])
        {
           g.dfs(i, visited);
        }
        
    }
    
    return 0;
}
