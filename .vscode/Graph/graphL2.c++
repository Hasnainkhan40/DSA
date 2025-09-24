#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <unordered_map>
#include <algorithm>   
#include <set>   
using namespace std;

template <typename T>


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

    void shortestPathBfs(int src, int dest) {
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int fNode = q.front();
        q.pop();

        for (auto nbr : adjList[fNode]) {
            int nbrNode = nbr.first;  // ignore weight since BFS works for unweighted graphs
            if (!visited[nbrNode]) {
                q.push(nbrNode);
                visited[nbrNode] = true;
                parent[nbrNode] = fNode;
            }
        }
    }

    // Reconstruct path
    vector<int> ans;
    int node = dest;
    while (node != -1) {
        ans.push_back(node);
        node = parent[node];
    }
    reverse(ans.begin(), ans.end());

    cout << "Printing the path: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;


}

void topoDfs(int src, unordered_map<int, bool> &visited, stack<int>& ans)
    {
        visited[src] = true;
    
       for (auto nbr : adjList[src]) {
            if (!visited[nbr.first]) {
                topoDfs(nbr.first, visited, ans);
            }
        }

        ans.push(src);
    }

void shortestPathDfs(int dest,  stack<int> topoOrder, int n){
    vector<int> dist(n, INT_MAX);
    int src = topoOrder.top();
    topoOrder.pop();
    dist[src] = 0;

    for(auto nbr: adjList[0]){
        if(dist[0] + nbr.second < dist[nbr.first]){
            dist[nbr.first] = dist[0] + nbr.second;
        }
    }

    while (!topoOrder.empty()){
        int topElement = topoOrder.top();
        topoOrder.pop();
        if(dist[topElement] != INT_MAX){
             for(auto nbr: adjList[topElement]){
                if(dist[topElement] + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dist[topElement] + nbr.second;
                }
            }

        }
    }
    cout << "Shortest distance from " << endl;
    for (int i = 0; i < n; i++) {
             cout << dist[i]<<" ";
    }
}

void shortestPathDijk(int src, int n) {
    vector<int> dist(n, INT_MAX);   // distance array
    set<pair<int, int>> st;         // {distance, node}
    
    dist[src] = 0;
    st.insert(make_pair(0, src));

    while (!st.empty()) {
        auto topElement = *(st.begin());
        int nodeDistance = topElement.first;
        int node = topElement.second;
        st.erase(st.begin());

        for (auto nbr : adjList[node]) {
            if (nodeDistance + nbr.second < dist[nbr.first]) {
                auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                if (result != st.end()) {
                    st.erase(result);
                }
                dist[nbr.first] = nodeDistance + nbr.second;
                st.insert(make_pair(dist[nbr.first], nbr.first));
            }
        }
    }

    cout << "Shortest distances from " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}





};




int main() {
    GraphWt<int> g;   
    int n = 5;

    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(3, 1, 9, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(4, 3, 11, 0);

    g.addEdge(6, 5, 9, 0);
    g.addEdge(4, 5, 6, 0);

    cout << endl;
    g.printAdjList();
    cout << endl;

    g.shortestPathDijk(6,7);

    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(4, 3, 1, 1);
   


    // cout << endl;
    // g.printAdjList();
    // cout << endl;

    // // g.shortestPathBfs(0, 3); 
    // int src = 0;
    // unordered_map<int, bool> visited;
    // stack<int> ans;
    // g.topoDfs(src, visited, ans);
    

   //g.shortestPathDfs(3 ,ans, n);

    

    return 0;
}
